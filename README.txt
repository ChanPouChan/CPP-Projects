Commands: g++ ASK3.cpp
	    ./a.out 2 3 3 3 3    (Τα Lj, Ls, Lt, N πάρουν τυχαίες τιμές, ο αριθμός των μαθητών είναι 2 για κάθε τάξη                                                       για να είναι ακριβώς όσοι είναι και στο αρχείο εισόδου)

**********************************
Classes about Person:
//////////////////////////
Class person(abstract) contains:
	constructors/destructor, getters/setters, print(pure virtual)
	string name, int floor_num, int class_num, bool in_class(Is he in class?), int fatigue(How tired is he?)

Class student(inherits person publicly) contains:
	2 static ints Lj, Lt, one for Junior one for Senior (rate of fatigue increase)
	constructors/destructor, attend, print

Class teacher(inherits person publicly) contains:
	static int Lt(rate of fatigue increase)
	constructors/destructor, teach, print
************************************
Classes about Area:
//////////////////////////
Class area(abstract) contains:
	constructor/destructor, enter(pure virtual)
	pointer to teacher, pointer to student, int hours

Class school(publicly inherits area) contains:
	constructor/destructor, enter, print, place, operate
	1 object of type yard, 1 object of type stair, 3 objects of type floor  (Has-a relationship)

Class yard(publicly inherits area) contains:
	constructor/destructor, enter, exit

Class stair(publicly inherits area) contains:
	constructor/destructor, enter, exit

Class floor(publicly inherits area) contains:
	constructor/destructor, enter, print, place, operate
	1 object of type corridor, 6 objects of type classroom  (Has-a realtionship)

Class corridor(publicly inherits area) contains:
	constructor/destructor, enter, exit

Class classroom(publicly inherits area) contains:
	static int Cclass(How many students can a classroom contain?)
	constructor/destructor, enter, print, place, operate
	array of pointers (unknown size) to student, pointer to teacher, int pos
****************************************

Θέματα υλοποίησης:

1) Teach αυξάνει την κούραση του καθηγητή με βάση το Lt και τις ώρες λειτουργίας(όρισμα)
    Attend αυξάνει την κούραση του μαθητή με βάση το Ls ή Lj και τις ώρες λειτουργίας(όρισμα)
    Ο τρόπος για τον L θα επιλέξει γίνεται με μία if, σύμφωνα με την εκφώνηση αν ο μαθητής βρίσκεται
    από 1-3 τάξη τότε Lj αλλιώς Ls.

2) Η μόνη μέθοδος που είναι κοινή για όλος τους χώρους είναι η enter που παίρνει έαν μαθητή(όρισμα)
    και τον τοποθετεί στον χώρο. Η enter του σχολείου καλεί διαδοχικά τις enter της αυλής, σκάλας και 
    αντίστοιχου ορόφου του μαθητή. Η enter του ορόφου καλεί διαδοχικά τις enter του διαδρόμου και της 
    αντίστοιχης τάξης του μαθητή.
    
3) Η print ουσιαστικά, με βάση την εκφώνηση, υπάρχει μόνο στο σχολείο, στους ορόφους και στις τάξεις. H print 
    του σχολείου καλεί εκείνη του ορόφου και ο κάθε όροφος καλεί αυτήν της τάξης. Η κάθε τάξη εκτυπώνει
    τους μαθητές και τον καθηγητή που βρίσκεται μέσα. 

4) Αντίστοιχα λειτουργούν με την print και οι place(όρισμα έναν καθηγητή) και operate(όρισμα ώρες λειτουργίας).
     Η place τελικά τοποθετεί τον καθηγητή στην τάξη του και η operate τελικά καλεί την attend για τους μαθητές
     και την teach για τον καθηγητή

5) Η exit υπάρχει μόνο εκεί που υπάρχει η ανάγκη να βγει ένας μαθητής δηλαδή στην αυλή, σκάλα και διάδρομο(κάνει
     return τον μαθητή)
*******************************************

Main:

1) Αποθήκευση των static και του Ν, από τη γραμμή εισόδου

2) Δημιουργία σχολείου, πίνακα μαθητών και καθηγητών(μεγέθη fixed λόγω αρχείων)

3) Εισαγώγη από αρχείο των μαθητών και των καθηγητών στους αντίστοιχους πίνακες

4) Τυχαία εισαγωγή των μαθητών από τον πίνακα της main στις τάξεις που ανήκουν. Το ίδιο για τους καθηγητές.
     Τα while/if υπάρχουν για να μην ξαναπάρει τον ίδιο μαθητή/καθηγητή και τον βάλει παραπάνω απο μία φορά

5) Λειτουργία σχολέιου και εκτύπωση

*******************************************   
:)	