class Scorer {
    public:
    int get_score();
    void start();
    void addRoll(int roll);
    private:
    int score;
    int frame_count;
    int last_roll;
    int next_bonus;
    int next_next_bonus;
    bool in_frame;
    void add_bonuses(int roll);
    void detect_specials(int roll);
    void update_score(int roll);
};
