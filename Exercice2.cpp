class Instrument
{
private:
    char *nom;
    double prix;
public:
    Instrument(const char *n, double p) : prix(p) {
}