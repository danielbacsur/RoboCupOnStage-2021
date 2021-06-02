#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

// Time between elements of final array (in seconds)
const double arrayTime = 0.5;
// Input array = {midi value, start time}
const double d[20] = {36, 0.00, 36, 1.00, 38, 2.00, 36, 3.00, 36, 4.00, 36, 5.00, 36, 5.50, 38, 6.00, 36, 6.00, 36, 7.00};

const int midi_length = 7;
const int midi[midi_length] = {38, 50, 51, 36, 42, 52, 53};
//snare, tom1, tom2, tom3, hh, ride, crash

void editFile(string str_replace)		//NEEDS EDITING
{
	ostringstream text;
	ifstream in_file("v2.ino");

	text << in_file.rdbuf();
	string str = text.str();
	size_t pos = str.find(" 5;");
	size_t pos2 = str.find("int m");
	str.replace(pos+4, pos2 - (pos+4), str_replace);
	in_file.close();

	ofstream out_file("v2.ino");
	out_file << str;
}

int main()
{
	//Generate empty array
	int size = (d[sizeof(d)/sizeof(double)-1])/arrayTime; //length of final array: length of track / arrayTime
    
    string f = "\nconst int d[" + to_string(size+1) + "] = {";
	string uf;
	for (int t=0;t<size;t++) { // t+1th atTime in g
		uf = "10000000";
		// loop through d
		for (int i = 1; i<sizeof(d)/sizeof(double); i+=2) {
			if (t*arrayTime == d[i]) {
				for (int j = 0; j<midi_length; j++) {
					if (midi[j] == d[i-1]) {
						uf[j+1] = '1';
						break;
					}
				}
			}
			// Is true if at time t p[i-1] is held down at time t
		}
		uf = to_string(stoi(uf, 0, 2)) + ", ";
		f += uf;
	}
	f += "128};\nconst int arrSize = " + to_string(size+1) + ";\nconst double arrayTime = " + to_string(arrayTime) + ";\n\n";
	//editFile(f);
	cout << f;
}
                                                                                                                                              
/*
                                    ___                                                ____                      ____                         ___     
                                  ,--.'|_                                            ,'  , `.                  ,'  , `.                     ,--.'|_   
                                  |  | :,'   ,---.    __  ,-.                     ,-+-,.' _ |   ,---.       ,-+-,.' _ |             ,---,   |  | :,'  
        .---.                    :  : ' :  '   ,'\ ,' ,'/ /|                  ,-+-. ;   , ||  '   ,'\   ,-+-. ;   , ||         ,-+-. /  |  :  : ' :  
      /.  ./|  ,---.     ,---. .;__,'  /  /   /   |'  | |' | ,---.           ,--.'|'   |  || /   /   | ,--.'|'   |  || ,---.  ,--.'|'   |.;__,'  /   
    .-' . ' | /     \   /     \|  |   |  .   ; ,. :|  |   ,'/     \         |   |  ,', |  |,.   ; ,. :|   |  ,', |  |,/     \|   |  ,"' ||  |   |    
    /___/ \: |/    /  | /    / ':__,'| :  '   | |: :'  :  / /    /  |        |   | /  | |--' '   | |: :|   | /  | |--'/    /  |   | /  | |:__,'| :    
    .   \  ' .    ' / |.    ' /   '  : |__'   | .; :|  | ' .    ' / |        |   : |  | ,    '   | .; :|   : |  | ,  .    ' / |   | |  | |  '  : |__  
    \   \   '   ;   /|'   ; :__  |  | '.'|   :    |;  : | '   ;   /|        |   : |  |/     |   :    ||   : |  |/   '   ;   /|   | |  |/   |  | '.'| 
      \   \  '   |  / |'   | '.'| ;  :    ;\   \  / |  , ; '   |  / |        |   | |`-'       \   \  / |   | |`-'    '   |  / |   | |--'    ;  :    ; 
      \   \ |   :    ||   :    : |  ,   /  `----'   ---'  |   :    |        |   ;/            `----'  |   ;/        |   :    |   |/        |  ,   /  
        '---" \   \  /  \   \  /   ---`-'                   \   \  /         '---'                     '---'          \   \  /'---'          ---`-'   
              `----'    `----'                              `----'                                                    `----'                         
                                                                                                                                                      
                                                                                                                                                      

          _____                    _____                    _____                    _____          
         /\    \                  /\    \                  /\    \                  /\    \         
        /::\    \                /::\____\                /::\    \                /::\    \        
       /::::\    \              /:::/    /               /::::\    \              /::::\    \       
      /::::::\    \            /:::/    /               /::::::\    \            /::::::\    \      
     /:::/\:::\    \          /:::/    /               /:::/\:::\    \          /:::/\:::\    \     
    /:::/__\:::\    \        /:::/    /               /:::/  \:::\    \        /:::/  \:::\    \    
    \:::\   \:::\    \      /:::/    /               /:::/    \:::\    \      /:::/    \:::\    \   
  ___\:::\   \:::\    \    /:::/    /      _____    /:::/    / \:::\    \    /:::/    / \:::\    \  
 /\   \:::\   \:::\    \  /:::/____/      /\    \  /:::/    /   \:::\    \  /:::/    /   \:::\    \ 
/::\   \:::\   \:::\____\|:::|    /      /::\____\/:::/____/     \:::\____\/:::/____/     \:::\____\
\:::\   \:::\   \::/    /|:::|____\     /:::/    /\:::\    \      \::/    /\:::\    \      \::/    /
 \:::\   \:::\   \/____/  \:::\    \   /:::/    /  \:::\    \      \/____/  \:::\    \      \/____/ 
  \:::\   \:::\    \       \:::\    \ /:::/    /    \:::\    \               \:::\    \             
   \:::\   \:::\____\       \:::\    /:::/    /      \:::\    \               \:::\    \            
    \:::\  /:::/    /        \:::\__/:::/    /        \:::\    \               \:::\    \           
     \:::\/:::/    /          \::::::::/    /          \:::\    \               \:::\    \          
      \::::::/    /            \::::::/    /            \:::\    \               \:::\    \         
       \::::/    /              \::::/    /              \:::\____\               \:::\____\        
        \::/    /                \::/____/                \::/    /                \::/    /        
         \/____/                  ~~                       \/____/                  \/____/         
                                                                                                    
                                                                                                    

 ▄▀▀▀▀▄  ▄▀▀█▄   ▄▀▀▄    ▄▀▀▄  ▄▀▄▄▄▄   ▄▀▀▀▀▄   ▄▀▀▄ ▀▄      ▄▀▀█▄▄   ▄▀▀█▄▄▄▄  ▄▀▀█▄▄▄▄  ▄▀▀▀▀▄    ▄▀▀▄ ▀▄  ▄▀▀▄ ▄▀▀▄  ▄▀▀▀█▀▀▄  ▄▀▀▀▀▄ 
█ █   ▐ ▐ ▄▀ ▀▄ █   █    ▐  █ █ █    ▌ █      █ █  █ █ █     █ ▄▀   █ ▐  ▄▀   ▐ ▐  ▄▀   ▐ █     ▄▀  █  █ █ █ █   █    █ █    █  ▐ █ █   ▐ 
   ▀▄     █▄▄▄█ ▐  █        █ ▐ █      █      █ ▐  █  ▀█     ▐ █    █   █▄▄▄▄▄    █▄▄▄▄▄  ▐ ▄▄▀▀    ▐  █  ▀█ ▐  █    █  ▐   █        ▀▄   
▀▄   █   ▄▀   █   █   ▄    █    █      ▀▄    ▄▀   █   █        █    █   █    ▌    █    ▌    █         █   █    █    █      █      ▀▄   █  
 █▀▀▀   █   ▄▀     ▀▄▀ ▀▄ ▄▀   ▄▀▄▄▄▄▀   ▀▀▀▀   ▄▀   █        ▄▀▄▄▄▄▀  ▄▀▄▄▄▄    ▄▀▄▄▄▄      ▀▄▄▄▄▀ ▄▀   █      ▀▄▄▄▄▀   ▄▀        █▀▀▀   
 ▐      ▐   ▐            ▀    █     ▐           █    ▐       █     ▐   █    ▐    █    ▐          ▐  █    ▐              █          ▐      
                              ▐                 ▐            ▐         ▐         ▐                  ▐                   ▐                 
                                                

__________________________________________________________________________________________________________/\\\_____________________________________________________________________________________________________        
 _________________________________________________________________________________________________________\/\\\_____________________________________________________________________________________________________       
  _________________________________________________________________________________________________________\/\\\______________________________________________________________________________/\\\___________________      
   __/\\\\\\\\\\__/\\\____/\\\__/\\____/\\___/\\_____/\\\\\\\\_____/\\\\\_____/\\/\\\\\\____________________\/\\\______/\\\\\\\\______/\\\\\\\\___/\\\\\\\\\\\__/\\/\\\\\\____/\\\____/\\\__/\\\\\\\\\\\__/\\\\\\\\\\_     
    _\/\\\//////__\/\\\___\/\\\_\/\\\__/\\\\_/\\\___/\\\//////____/\\\///\\\__\/\\\////\\\______________/\\\\\\\\\____/\\\/////\\\___/\\\/////\\\_\///////\\\/__\/\\\////\\\__\/\\\___\/\\\_\////\\\////__\/\\\//////__    
     _\/\\\\\\\\\\_\/\\\___\/\\\_\//\\\/\\\\\/\\\___/\\\__________/\\\__\//\\\_\/\\\__\//\\\____________/\\\////\\\___/\\\\\\\\\\\___/\\\\\\\\\\\_______/\\\/____\/\\\__\//\\\_\/\\\___\/\\\____\/\\\______\/\\\\\\\\\\_   
      _\////////\\\_\/\\\___\/\\\__\//\\\\\/\\\\\___\//\\\________\//\\\__/\\\__\/\\\___\/\\\___________\/\\\__\/\\\__\//\\///////___\//\\///////______/\\\/______\/\\\___\/\\\_\/\\\___\/\\\____\/\\\_/\\__\////////\\\_  
       __/\\\\\\\\\\_\//\\\\\\\\\____\//\\\\//\\\_____\///\\\\\\\\__\///\\\\\/___\/\\\___\/\\\___________\//\\\\\\\/\\__\//\\\\\\\\\\__\//\\\\\\\\\\__/\\\\\\\\\\\_\/\\\___\/\\\_\//\\\\\\\\\_____\//\\\\\____/\\\\\\\\\\_ 
        _\//////////___\/////////______\///__\///________\////////_____\/////_____\///____\///_____________\///////\//____\//////////____\//////////__\///////////__\///____\///___\/////////_______\/////____\//////////__


           ,.         ,·´'; '        ,.-·.            .,                       .,                         ,.  '                      _,.,  °                 ,. -,    
      ;'´*´ ,'\       ,'  ';'\°      /    ;'\'      ,·´    '` ·.'             ,·´    '` ·.'                 /   ';\               ,.·'´  ,. ,  `;\ '         ,.·'´,    ,'\   
      ;    ';::\      ;  ;::'\     ;    ;:::\      \`; `·;·.   `·,          \`; `·;·.   `·,           ,'   ,'::'\            .´   ;´:::::\`'´ \'\     ,·'´ .·´'´-·'´::::\' 
     ;      '\;'      ;  ;:::;    ';    ;::::;'      ;   ,'\::`·,   \'         ;   ,'\::`·,   \'        ,'    ;:::';'          /   ,'::\::::::\:::\:'   ;    ';:::\::\::;:'  
    ,'  ,'`\   \      ;  ;:::;     ;   ;::::;      ;   ,'::'\:::';   ';       ;   ,'::'\:::';   ';       ';   ,':::;'          ;   ;:;:-·'~^ª*';\'´     \·.    `·;:'-·'´     
    ;  ;::;'\  '\    ;  ;:::;     ';  ;'::::;       ;   ;:::;'·:.'  ,·'\'      ;   ;:::;'·:.'  ,·'\'      ;  ,':::;' '          ;  ,.-·:*'´¨'`*´\::\ '     \:`·.   '`·,  '     
   ;  ;:::;  '\  '\ ,'  ;:::;'     ;  ';:::';       ';  ';: -· '´. ·'´:::'\'    ';  ';: -· '´. ·'´:::'\'    ,'  ,'::;'            ;   ;\::::::::::::'\;'        `·:'`·,   \'      
  ,' ,'::;'     '\   ¨ ,'\::;'      ';  ;::::;'      ;  ,-·:'´:\:::::::;·'     ;  ,-·:'´:\:::::::;·'     ;  ';_:,.-·´';\     ;  ;'_\_:;:: -·^*';\         ,.'-:;'  ,·\     
  ;.'\::;        \`*´\::\; °      \*´\:::;     ,'  ';::::::'\;:·'´        ,'  ';::::::'\;:·'´         ',   _,.-·'´:\:\    ';    ,  ,. -·:*'´:\:'\°  ,·'´     ,.·´:::'\    
  \:::\'          '\:::\:' '         '\::\:;'      \·.,·\;-· '´  '           \·.,·\;-· '´  '             \¨:::::::::::\';     \`*´ ¯\:::::::::::\;' '  \`*'´\::::::::;·'   
    \:'             `*´'             `*´        \::\:\                   \::\:\                     '\;::_;:-·'´         \:::::\;::-·^*'´        \::::\:;:·´        
                                                  `'·;·'                    `'·;·'                       '¨                    `*´¯                   '`*'´            
                                                  
                                                  


*/    
/*    

|\     /|\__   __/\__   __/(  ____ )(  ____ \        /\ /\|\     /||\     /||\     /|   (  ____ )(  ___  )\__   __/(  ___  )(  ____ )\__    _/| \    /\   (  ____ \(  ___  )(       )     /\(  ____ \(  ___  )(  ____ \\__   __/|\     /|(  ___  )(  ____ )(  ____ \     /\\__   __/(  ___  )(  ___  )(  ____ \     /\ ( ) ( )  (  ____ )     (  __  \ \__   __/(  ____ \(  ____ )( \      (  ___  )|\     /| /__\  (  ____ \   / ___  \ (  __  \      /\/ ___   )(  __   )(  __  \ \__   __/(  ___  )(  ____ \(  ___  )( (    /|(  ___  )( \        /__\\__   __/  |\     /|(  ____ \(  ____ \\__   __/(  ___  )(  ____ )(  ____ \     /\/ ___   )(  __   )(       )(  ___  )(       )(  ____ \( (    /|\__   __/
| )   ( |   ) (      ) (   | (    )|| (    \/ _     / // /| )   ( || )   ( || )   ( |   | (    )|| (   ) |   ) (   | (   ) || (    )|   )  (  |  \  / /   | (    \/| (   ) || () () |    / /| (    \/| (   ) || (    \/   ) (   | )   ( || (   ) || (    )|| (    \/    / /   ) (   | (   ) || (   ) || (    \/    / /_| |_| |_ | (    )| ___ | (  \  )   ) (   | (    \/| (    )|| (      | (   ) |( \   / )( \/ ) | (    \/___\/   \  \| (  \  )()  / /\/   )  || (  )  || (  \  )   ) (   | (   ) || (    \/| (   ) ||  \  ( || (   ) || (       ( \/ )  ) ( ___ | )   ( || (    \/| (    \/   ) (   | (   ) || (    )|| (    \/()  / /\/   )  || (  )  || () () || (   ) || () () || (    \/|  \  ( |   ) (   
| (___) |   | |      | |   | (____)|| (_____ (_)   / // / | | _ | || | _ | || | _ | |   | (____)|| (___) |   | |   | |   | || (____)|   |  |  |  (_/ /    | |      | |   | || || || |   / / | (_____ | |   | || (__       | |   | | _ | || (___) || (____)|| (__       / /    | |   | (___) || (___) || |         / /(_   _   _)| (____)|(___)| |   ) |   | |   | (_____ | (____)|| |      | (___) | \ (_) /  \  /  | (__   (___)  ___) /| |   ) |   / /     /   )| | /   || |   ) |   | |   | (___) || |      | |   | ||   \ | || (___) || |        \  /   | |(___)| |   | || (__    | |         | |   | |   | || (____)|| (__       / /     /   )| | /   || || || || |   | || || || || (__    |   \ | |   | |   
|  ___  |   | |      | |   |  _____)(_____  )     / // /  | |( )| || |( )| || |( )| |   |  _____)|  ___  |   | |   | |   | ||     __)   |  |  |   _ (     | |      | |   | || |(_)| |  / /  (_____  )| |   | ||  __)      | |   | |( )| ||  ___  ||     __)|  __)     / /     | |   |  ___  ||  ___  || | ____   / /  _| (_) |_ |  _____) ___ | |   | |   | |   (_____  )|  _____)| |      |  ___  |  \   /   /  \/\|  __)   ___  (___ ( | |   | |  / /    _/   / | (/ /) || |   | |   | |   |  ___  || | ____ | |   | || (\ \) ||  ___  || |        /  \/\ | | ___ ( (   ) )|  __)   | |         | |   | |   | ||     __)|  __)     / /    _/   / | (/ /) || |(_)| || |   | || |(_)| ||  __)   | (\ \) |   | |   
| (   ) |   | |      | |   | (            ) | _  / // /   | || || || || || || || || |   | (      | (   ) |   | |   | |   | || (\ (      |  |  |  ( \ \    | |      | |   | || |   | | / /         ) || |   | || (         | |   | || || || (   ) || (\ (   | (       / /      | |   | (   ) || (   ) || | \_  ) / /  (_   _   _)| (      (___)| |   ) |   | |         ) || (      | |      | (   ) |   ) (   / /\  /| (     (___)     ) \| |   ) | / /    /   _/  |   / | || |   ) |   | |   | (   ) || | \_  )| |   | || | \   || (   ) || |       / /\  / | |(___) \ \_/ / | (      | |         | |   | |   | || (\ (   | (       / /    /   _/  |   / | || |   | || |   | || |   | || (      | | \   |   | |   
| )   ( |   | |      | |   | )      /\____) |(_)/ // /    | () () || () () || () () | _ | )      | )   ( |   | |   | (___) || ) \ \__|\_)  )  |  /  \ \ _ | (____/\| (___) || )   ( |/ /    /\____) || (___) || )         | |   | () () || )   ( || ) \ \__| (____/\/ /       | |   | )   ( || )   ( || (___) |/ /     | | | |  | )           | (__/  )___) (___/\____) || )      | (____/\| )   ( |   | |  (  \/  \| )         /\___/  /| (__/  )/ /  ()(   (__/\|  (__) || (__/  )___) (___| )   ( || (___) || (___) || )  \  || )   ( || (____/\(  \/  \ | |       \   /  | (____/\| (____/\   | |   | (___) || ) \ \__| (____/\/ /  ()(   (__/\|  (__) || )   ( || (___) || )   ( || (____/\| )  \  |   | |   
|/     \|   )_(      )_(   |/       \_______)   \/ \/     (_______)(_______)(_______)(_)|/       |/     \|   )_(   (_______)|/   \__/(____/   |_/    \/(_)(_______/(_______)|/     \|\/     \_______)(_______)|/          )_(   (_______)|/     \||/   \__/(_______/\/        )_(   |/     \||/     \|(_______)\/      (_) (_)  |/            (______/ \_______/\_______)|/       (_______/|/     \|   \_/   \___/\/|/          \______/ (______/ \/     \_______/(_______)(______/ \_______/|/     \|(_______)(_______)|/    )_)|/     \|(_______/ \___/\/ )_(        \_/   (_______/(_______/   )_(   (_______)|/   \__/(_______/\/     \_______/(_______)|/     \|(_______)|/     \|(_______/|/    )_)   )_(   
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

*/  


/*

 ▄▀▀▀▀▄  ▄▀▀▀▀▄   ▄▀▀▄ ▄▀▄  ▄▀▀█▄▄▄▄  ▄▀▀▀█▄    ▄▀▀█▀▄    ▄▀▀▄ ▀▄  ▄▀▀▀▀▄   
█ █   ▐ █      █ █  █ ▀  █ ▐  ▄▀   ▐ █  ▄▀  ▀▄ █   █  █  █  █ █ █ █         
   ▀▄   █      █ ▐  █    █   █▄▄▄▄▄  ▐ █▄▄▄▄   ▐   █  ▐  ▐  █  ▀█ █    ▀▄▄  
▀▄   █  ▀▄    ▄▀   █    █    █    ▌   █    ▐       █       █   █  █     █ █ 
 █▀▀▀     ▀▀▀▀   ▄▀   ▄▀    ▄▀▄▄▄▄    █         ▄▀▀▀▀▀▄  ▄▀   █   ▐▀▄▄▄▄▀ ▐ 
 ▐               █    █     █    ▐   █         █       █ █    ▐   ▐         
                 ▐    ▐     ▐        ▐         ▐       ▐ ▐                  

*/
