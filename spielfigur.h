#ifndef SPIELFIGUR_H
#define SPIELFIGUR_H


class spielfigur
{
    public:
        spielfigur();
        virtual ~spielfigur();

        spielfigur(int xpos, int ypos, bool gefangen, bool team, bool koenig, bool ziehen)
        : xpos(xpos), ypos(ypos), gefangen(gefangen), team(team), koenig(koenig), ziehen(ziehen)
        {}

        int Getxpos() { return xpos; }
        void Setxpos(int val) { xpos = val; }
        int Getypos() { return ypos; }
        void Setypos(int val) { ypos = val; }
        bool Getgefangen() { return gefangen; }
        void Setgefangen(bool val) { gefangen = val; }
        bool Getteam() { return team; }
        void Setteam(bool val) { team = val; }
        bool Getkoenig() { return koenig; }
        void Setkoenig(bool val) { koenig = val; }
        bool Getziehen() {return ziehen;}
        void Setziehen(bool val) {ziehen=val;}
        void bewegen(int x,int y){
            xpos=x;
            ypos=y;
            ziehen=0;
        }

    protected:

    private:
        int xpos;
        int ypos;
        bool gefangen;
        bool team;
        bool koenig;
        bool ziehen;
};

#endif // SPIELFIGUR_H
