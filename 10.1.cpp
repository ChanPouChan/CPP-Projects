#include <iostream>
using namespace std;
#define SIZE 100

class video
{
	public:
		int get_duration() const;
		void set_video(string artist_, string song_name_,int duration_);
		friend ostream &operator<<(ostream &left, const video &ob);
		string get_song_name() const;
	private:
		string artist;
		string song_name;
		int duration;
};

class playlist
{
	public:
		playlist(string name_, string description_);
		void add_video(video in_video);
		friend ostream &operator<<(ostream &left, const playlist &ob);
	protected:
		string name;
		string description;
		int duration;
		video videos[SIZE];
		int videos_size;
};

class classical_playlist:public playlist
{
	public:
		classical_playlist(string name_, string description_, string period_);
		friend ostream &operator<<(ostream &left, const classical_playlist &ob);
	private:
		string period;
};

int main()
{
//	playlist l("My Playlist", "Only the best songs");
	classical_playlist c("Classical Music ","Most classical songs","Classical");
	video temp;
	
	temp.set_video("Drake", "Controlla", 300);
	c.add_video(temp);
	temp.set_video("Drake", "God's Plan'", 500);
	c.add_video(temp);  
	
//	cout<<l;
	cout<<c;
	
	return 0;
}

int video::get_duration() const
{
	return duration;
}

string video::get_song_name() const
{
	return song_name;
}

void video::set_video(string artist_, string song_name_,int duration_)
{
	artist = artist_;
	song_name = song_name_;
	duration = duration_;	
}

ostream &operator<<(ostream &left, const video &ob)
{
	left<<"Song Name: "<<ob.song_name<<" Artist: "<<ob.artist<<" Duration: "<<ob.duration;
	
	return left;
} 

playlist::playlist(string name_, string description_)
{
	name = name_;
	description = description_;
	duration = 0;
	videos_size = 0;	
}

void playlist::add_video(video in_video)
{
	if(videos_size < SIZE)
	{
		videos[videos_size] = in_video;
		videos_size++;
		duration+=in_video.get_duration(); 
		cout<<"Video "<<in_video.get_song_name()<<" was added"<<endl;
	}
	else
		cout<<"Video "<<in_video.get_song_name()<<" was not added"<<endl;
}

ostream &operator<<(ostream &left, const playlist &ob)
{
	left<<"Playlist Name: "<<ob.name<<" Description: "<<ob.description<<" Duration: "<<ob.duration<<endl;
	cout<<"Song list: "<<endl;
	
	for(int i=0; i<ob.videos_size; i++)
		left<<ob.videos[i]<<endl;
		
	return left;	
}

classical_playlist::classical_playlist(string name_, string description_, string period_):
	playlist(name_,description_)
{
	period = period_;
} 

ostream &operator<<(ostream &left, const classical_playlist &ob)
{
	left<<"Playlist Name: "<<ob.name<<" Description: "<<ob.description<<" Period: "<<ob.period<<" Duration: "<<ob.duration<<endl;
		cout<<"Song list: "<<endl;
	
		for(int i=0; i<ob.videos_size; i++)
			left<<ob.videos[i]<<endl;
		
	return left;
}
