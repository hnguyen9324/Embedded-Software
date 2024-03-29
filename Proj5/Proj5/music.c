/*
 * music.c
 *
 * Created: 6/2/2018 2:01:26 PM
 *  Author: Danny
 */ 
 #include "music.h"
 #include "avr.h"


void init_speaker()
 {
	 SET_BIT(DDRA,0);
	 SET_BIT(PORTA,0);
 }

void play_note(int freq, int dur)
{
	double period = (1.0 / freq) * 10000; // 440HZ = 2.27 ms in 1 sec
	double t = period/2;
	double k = freq * dur * NORMAL;
	for (int i = 0; i < k; ++i)
	{
		SET_BIT(PORTA, 0);
		wait_avr(t);
		CLR_BIT(PORTA, 0);
		wait_avr(t);
	}
}

void play_note2(int freq, int dur, double speed)
 {
	 double period = (1.0 / freq) * 10000; // 440HZ = 2.27 ms in 1 sec
	 double t = period/2;
	 double k = freq * dur * speed;
	 for (int i = 0; i < k; ++i)
	 {
		 SET_BIT(PORTA, 0);
		 wait_avr(t);
		 CLR_BIT(PORTA, 0);
		 wait_avr(t);
	 }
 }

void play_music(struct note *song, int n) // n = number of note in the song array
 {
	 for (int i = 0; i < n;++i)
	 {
		 play_note(song[i].freq, song[i].dur);
		 wait_avr(100);
	 }
 }

void play_music2(struct note *song, int n, double speed) // n = number of note in the song array
{
	for (int i = 0; i < n;++i)
	{
		play_note2(song[i].freq, song[i].dur, speed);
		wait_avr(100);
	}
}


 /***************** SONG ******************/
 void happyBirthday(double speed)
 {
	 struct note song[] = {
		 { C4, 1  }, //1
		 { C4, 1  }, //1
		 { D4, 1  }, //2
		 { C4, 1  }, //1
		 { F4, 1  }, //4
		 { E4, 1  }, //3
		 { C4, 2  }, //1
		 { C4, 1  }, //1
		 { D4, 1  }, //2
		 { C4, 1  }, //1
		 { G4, 1  }, //5
		 { F4, 1  }, //4
		 { C4, 1  }, //1
		 { C4, 1  }, //1
		 { C5, 1  }, //8
		 { A4, 1  }, //6
		 { F4, 1  }, //4
		 { E4, 1  }, //3
		 { D4, 1  }, //2
		 { B4, 2  }, //7
		 { F4, 1  }, //4
		 { G4, 1  }, //5
		 { F4, 1  }  //4
	 };
	 play_music2(song, 23, speed); //has 23 notes
 }

 void twinkleStar(double speed)
 {
	 struct note song[] = {
		 // verse 1
		 { C4, 1  },
		 { C4, 1  },
		 { G4, 1  },
		 { G4, 1  },
		 { A4, 1  },
		 { A4, 1  },
		 { G4, 2  },
		 { F4, 1  },
		 { F4, 1  },
		 { E4, 1  },
		 { E4, 1  },
		 { D4, 1  },
		 { D4, 1  },
		 { C4, 2  },
		 // verse 2
		 { G4, 1  },
		 { G4, 1  },
		 { F4, 1  },
		 { F4, 1  },
		 { E4, 1  },
		 { E4, 1  },
		 { D4, 2  },
		 // verse 3
		 { G4, 1  },
		 { G4, 1  },
		 { F4, 1  },
		 { F4, 1  },
		 { E4, 1  },
		 { E4, 1  },
		 { D4, 2  },
		 // verse 4
		 { C4, 1  },
		 { C4, 1  },
		 { G4, 1  },
		 { G4, 1  },
		 { A4, 1  },
		 { A4, 1  },
		 { G4, 2  },
		 { F4, 1  },
		 { F4, 1  },
		 { E4, 1  },
		 { E4, 1  },
		 { D4, 1  },
		 { D4, 1  },
		 { C4, 3  }
	 };
	 play_music2(song, 42, speed); //has 42 notes
 } 

 void twinkleStarShort(double speed) //14 note
  {
	  struct note song[] = {
		  // verse 1
		  { C4, 1  },
		  { C4, 1  },
		  { G4, 1  },
		  { G4, 1  },
		  { A4, 1  },
		  { A4, 1  },
		  { G4, 2  },
		  { F4, 1  },
		  { F4, 1  },
		  { E4, 1  },
		  { E4, 1  },
		  { D4, 1  },
		  { D4, 1  },
		  { C4, 2  }
	  };
	  play_music2(song, 14, speed); //has 14 notes
  }


