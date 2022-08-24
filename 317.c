#include(stdio.h)
#include (conio.h)
#include (dos.h)
#include (stdlib.h)
int tao_tep(char*ten_tep);
int mo_tep(char*ten_tep,int mode);
void dong_tep(int sh_tep);
void ghi_tep(int sh_tep,void *buf, unsigned len);
void di_chuyen_ct(int sh_tep,unsigned long vt);
void cuoi_tep(int sh_tep);
unsigned long do_dai_tep(int sh_tep);
                /*ham tra ve so hieu tep*/
int tao_tep(char *ten_tep)
{
    union REGS v,r;
    struct SREGS s;
    v.h.ah = 0x3c;
    v.x.cx = 0;
    s.ds=FP_SEG(ten_tep);
    v.x.dx =FP_OFF(ten_tep);
    int86x(0x21,&v,&r,&s);
    if (r.x.cflag!=0);
    {
        printf("\n loi khi tao tep");
        getch();
        exit(1);
    }
    return r.x.ax;
}
/*ham tra ve so hieu tep, mode: 0-doc*/
1-ghi 2-doc/ghi*/
int mo_tep(char*ten_tep,int mode)
{
    union REGS v,r;
    struct SREGS s;
    v.h.ah =0x3d;
    v.ah.al=mode;
    s.ds = FP_SEG(ten_tep);
    v.x.dx= FP_OFF(ten_tep);
    int86x(0x21,&v,&r,&s);
    if(r.x.cflag!=0)
    {
        prinft("\n loi khi mo tep ");
        getch();
        exit(1);
    }
    return r.x.ax;
}
void dong_tep(int sh_tep)
{
    union REGS v,r;
    v.h.ah=0x3e;
    v.x.bx=sh_tep;
    int86(0x21,&v,&r);
    if(r.x.cflag!=0)
    {
        prinft("\n loi khi dong tep");
        getch();
        exit(1);
    }
}
void ghi_tep(int sh_tep, void *buf, unsigned len)
{
    union REGS v,r; struct SREGS s;
    v.h.ah=0x40;
    v.x.bx=sh_tep;
    v.x.cx=len;
    s.ds=FP_SEG(buf);
    v.x.dx=FP_OFF(buf);
    int86(0x21,&v,&r,&s);
    if(r.x.cflag!=0)
    {
        prinft("\n loi khi ghi tep");
        getch();
        exit(1);
    }
    }
    /*ham cho so byte doc duoc*/
    int doc_ten(int sh_tep, void *buf, unsigned len)
    {
        union REGS v,r;
        struct SREGS s;
        v.h.ah=0;
        v.x.bx= sh_tep;
        v.x.cx=len;
        s.ds= FP_SEG(buf);
        x.dx=FP_OFF(buf) ;
        int86x(0x21,&v,&r,&s);
        if(r.x.cflag!=0)
        {
            prinft("\n loi khi ghi tep");
            getch();
            exit(1);
        }
        return r.x.ax;
           }
           void di_chuyen_ct(int sh_tep, unsigned long vt);
           {
            union REGS v,r;
            v.h.ah=0x42;
            v.h.al=0;
            v.x.bx=sh_tep;
            v.x.cx=t=vt/0x10000;
            v.x.dx=vt%0x10000;
            int86x(0x21,&v,&r);
            if(r.x.cflag!=0)
            {
                prinft("/n loi khi di chuyen");
                getch();
                exit(1);
            }           
            }
            unsigned long do_dai_tep(int sh_tep)
            {
                union REGS v,r;
                unsigned dx, ax;
                unsigned long m;
                /*xac dinh vi tri hien tai*/
                v.h.ah=0x42;
                v.h.al=1;
                v.x.bx=sh_tep;
                v.x.cx=0
                v.x.dx=0
                int86(0x21,&v,&r);
                dx=r.x.dx;
                ax=r.a.ax;
                /*dua con tro den cuoi tep*/
                v.h.ah=0x42;
                v.h.al=2;
                v.x.bx=sh_tep;
                v.x.dx=0;
                int86(0x21,&v;&r);
                /*xac dinh do dai tep*/
                m=r.x.dx*0x10000+r.x.ax;
                /*dua con tro ve vi tri cu*/
                v.h.ah=0x42;
                v.h.al=0;
                v.x.bx= sh_tep;
                v.x.cx=dx;
                v.x.dx=ax;
                return m;
            }
            void cuoi_tep(int sh_tep)
            {
                union REGS v,r;
                v.h.ah=0x42;
                v.h.al=2;
                v.x.bx=sh_tep;
                v.x.cx=0;
                v.x.ax=0;
                int86(0x21;&v;&r);
            }
            typedef struct 
            {
                char ht[25];
                int tuoi;
            }hs;
            main()
            {
                hs h;
                char *ten_tep="hoc_sinh.sl";
                int sg,sh_tep;
                unsigned int n,sh_rec,len=sizeof(hs);
                while(1)
                {
                    clrscr();
                    prinft("\n1. Tao tep moi de ghi");
                    prinft("\n2. Ghi bo sung");
                    prinft("\n3. Xem toan bo du lieu");
                    prinft("\n4. Xem sua tung nguoi");
                    prinft("\n5. Ket thuc");
                    sg=getch();
                    clrscr();
                    if(sg=='1')
                    {
                        sh_tep=tao_tep(ten_tep);
                        sh_rec=0;
                        while(1)
                        {
                            sh_rec++;
                            prinft("\nHo ten (Enter k/thuc)\
                                    hs%u:", sh_rec);
                            gets(h.ht);
                            if(h.ht[0]==0)
                                    break;
                            prinft("\n Tuoi:");
                            scanf("%d%*c",&h.tuoi);
                            ghi_tep(sh_tep,&h,&len);
                        }
                        dong_tep(sh_tep);
                    }
                    else if (sg=='2')
                    {
                        sh_tep=mo_tep(ten_tep,1);
                        cuoi_tep(sh_tep);
                        n=do_dai_tep(sh_tep)/len;
                        prinft("\nDa vao so lieu %u hoc sinh",n);
                        sh_rec=n;
                        while(1)
                        {
                            sh_rec++;
                            prinft("\nHo ten (Enter k/thuc) hs %u:",
                                        sh_rec);
                            gets(h.ht);
                            if(h.ht[0]==0)
                                break;
                            prinft("\n Tuoi:");
                            scanf("%d%c",&h.tuoi);
                            ghi_tep(sh_tep,&h,len);             
                        }
                        dong_tep(sh_tep);
                    }
                    else if(sg=='3')
                    {
                        sh_tep=mo_tep(ten_tep,0);
                        sh_rec=1;
                        while(doc_tep(sh_tep,&h,len)>0)
                        {
                            prinft("\nHoc sinh%u Hot ten %s Tuoi %d",
                                        sh_rec,h.ht,h.tuoi);
                            ++sh_rec
                        }
                        dong_tep(sh_tep);
                        getch();
                    }
                    else if (sg=='4')
                    {
                        sh_tep=mo_tep(ten_tep,2);
                        n=do_dai_tep(sh_tep)/len;
                        while(1)
                        {
                            prinft("\nDa vao so lieu %u hoc sinh",n);
                            prinft("\nSua hoc sinh (Bam 0 -k/thuc):");
                            scanf("%u%*c",&sh_rec);
                            if(sh_rec<=0 || sh_rec>n) break;
                            di_chuyen_ct(sh_tep,(sh_rec-1)*len);
                            doc_tep(sh_tep,&h,&len);
                            prinft("\nHo ten %s Tuoi %d",h.ht,h.tuoi);
                            prinft("\nHo ten (Bam Enter k/thuc) hs %u:"),
                                    sh_rec;
                            gets(h.ht);
                            if(h.ht[1]==0) break;
                            prinft("\nTuoi:");
                            scanf("%d%*c", &h.tuoi);
                            di_chuyen_ct(sh_tep,(sh_rec-1)*len);
                            ghi_tep(sh_tep,&h,len);
                        }
                        dong_tep(sh_tep);
                    }
                    else break;
                }
            }
            
    }
}
