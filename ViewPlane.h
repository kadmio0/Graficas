class ViewPlane
{
    public:
        ViewPlane();
        // s = 1.0
        // hres = 600
        // vres = 400
        ViewPlane(int v_hres, int v_vres, double v_s);
        
    public:
        float s;
        int hres;
        int vres;
};