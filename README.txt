Commands: g++ ASK1.cpp -o a
	    ./a 2 18 6 9

Class student contains :
	const/destr, copy const, getters/setters, print 
	name, floor=f ,class = c, location

Class teacher contains :
	const/destr, copy const, getters/setters, print 
	name, floor=f ,class = c, in= in or not in class

Class classroom containts :
	const/destr, enter, print ,static variable 
	array of pointers to students 

Class corr(corridor) contains :
	const/destr, getter, enter/exit, print, static variable
	array of pointers to students

Class yard contains :
	const/destr, getter, enter/exit, print, static variable
	array of pointers to students

Class yard contains :
	const/destr, getter, enter/exit, print, static variable
	array of pointers to students

Class yard contains :
	const/destr, getter, enter/exit, print 
	1 object of type corr(corridor)
	6 objects of type classroom

Class school contains :
	const/destr, getter, print, place(calls teachers's place), exit/enter of different classes(each one calls the 	respective enter/exit)
	array of students, array of teachers (That are filled though files)
	1 object of type yard
	1 object of type stair 
	3 objects of type floor 

Η γενική ιδεά είναι κάθε χώρος/κλάση να χρησιμοποιεί τον πίνακα δεικτών του σε αντικείμενα τύπου student , έτσι
ώστε κάθε φορά να δείχνουν στους μαθητές του σχολείου(πίνακας student της κλάσης school). Κάθε φορά που ένας μάθητης μπαίνει στο χώρο ο δείκτης δείχνει σε αυτόν. Κάθε φορά που βγαίνει ένας μαθητής βάζουμε τον δείκτη να δείχνει σε NULL και τον επιστρέφουμε έτσι ώστε να περαστεί σαν όρισμα στο επόμενο enter(δεν επιστρέφω τον 
ίδιο τον μαθητή αλλά την διέυθυνσή του)

Main:

1. Πέρασμα στις static μεταβλητές τα μεγέθη από την γραμμή εντολών( οι static χρησιμοποιούνται στις εκτυπώσεις 
    των χώρων)

2. Ορισμός μετρητών , δημιουργία σχολείου

3. Η εισαγωγή των μαθητών θα γίνεται όσο οι καθηγητές δεν είναι όλοι μέσα και όσο δεν είναι όλοι οι μαθητές μέσα

4. Εισαγωγή των μαθητών στην αυλή -> εισαγωγή των μαθητών στο κλιμακοστάσιο -> εισαγωγή των μαθητών στον     αντίστοιχο όροφο τους (η εισαγωγή τους στον διάδρομο πρακτικά) -> εισαγωγή τους στην αντίστοιχη τάξη τους

5. Εισαγωγή τυχαίας ποσότητας καθηγητών στις τάξεις τους

6.Συνέχεια της εισαγωγής των μαθητών αλλιώς εκτύπωση του σχολείου


Σε Windows τρέχει κανονικά ενώ σε linux άλλοτε έχω segmentation fault και άλλοτε τρέχει κανονικά 
Για την τυχαία εισαγώγη των μαθητών/καθηγητών απλά αλλάζω την σειρά τους μέσα στα αρχεία( δεν μπορούσα να σκεφτώ άλλον τρόπο τυχαίας εισαγωγής τους ). 
