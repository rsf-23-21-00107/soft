#ifndef __NONLINEAR_PROBLEM_OVERSCREENING_BREAKDOWN_KER_DETAIL_PROBLEM_H__
#define __NONLINEAR_PROBLEM_OVERSCREENING_BREAKDOWN_KER_DETAIL_PROBLEM_H__

#include <contrib/scfd/include/scfd/utils/device_tag.h>
#include "compute_infinity_cuda.h"

namespace detail
{

template<class T>
struct overscreening_breakdown_problem
{
    overscreening_breakdown_problem(size_t N_p, int parameter_number_p, T sigma_p, T L_p, T delta_p, T gamma_p, T mu_p, T u0_p ):
    N(N_p), parameter_number_(parameter_number_p), L(L_p), delta(delta_p), gamma(gamma_p), mu(mu_p), u0(u0_p), sigma(sigma_p), which(0)
    {}
    
    __DEVICE_TAG__ inline T pi()
    {
        return static_cast<T>(3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882353787593751957781857780532171226806613001927876611195909216420198938095257201065485863278865936153381827968230301952035301852968995773622599413891249721775283479131515574857242454150695950829533116861727855889075098381754637464939319255060400927701671139009848824012858361603563707660104710181942955596198946767837449448255379774726847104047534646208046684259069491293313677028989152104752162056966024058038150193511253382430035587640247496473263914199272604269922796782354781636009341721641219924586315030286182974555706749838505494588586926995690927210797509302955321165344987202755960236480665499119881834797753566369807426542527862551818417574672890977772793800081647060016145249192173217214772350141441973568548161361157352552133475741849468438523323907394143334547762416862518983569485562099219222184272550254256887671790494601653466804988627232791786085784383827967976681454100953883786360950680064225125205117392984896084128488626945604241965285022210661186306744278622039194945047123713786960956364371917287467764657573962413890865832645995813390478027590099465764078951269468398352595709825822620522489407726719478268482601476990902640136394437455305068203496252451749399651431429809190659250937221696461515709858387410597885959772975498930161753928468138268683868942774155991855925245953959431049972524680845987273644695848653836736222626099124608051243884390451244136549762780797715691435997700129616089441694868555848406353422072225828488648158456028506016842739452267467678895252138522549954666727823986456596116354886230577456498035593634568174324112515076069479451096596094025228879710893145669136867228748940560101503308617928680920874760917824938589009714909675985261365549781893129784821682998948722658804857564014270477555132379641451523746234364542858444795265867821051141354735739523113427166102135969536231442952484937187110145765403590279934403742007310578539062198387447808478489683321445713868751943506430218453191048481005370614680674919278191197939952061419663428754440643745123718192179998391015919561814675142691239748940907186494231961567945208095146550225231603881930142093762137855956638937787083039069792077346722182562599661501421503068038447734549202605414665925201497442850732518666002132434088190710486331734649651453905796268561005508106658796998163574736384052571459102897064140110971206280439039759515677157700420337869936007230558763176359421873125147120532928191826186125867321579198414848829164470609575270695722091756711672291098169091528017350671274858322287183520935396572512108357915136988209144421006751033467110314126711136990865851639831501970165151168517143765761835155650884909989859982387345528331635507647918535893226185489632132933089857064204675259070915481416549859461637180270981994309924488957571282890592323326097299712084433573265489382391193259746366730583604142813883032038249037589852437441702913276561809377344403070746921120191302033038019762110110044929321516084244485963766983895228684783123552658213144957685726243344189303968642624341077322697802807318915441101044682325271620105265227211166039666557309254711055785376346682065310989652691862056476931257058635662018558100729360659876486117910453348850346113657686753249441668039626579787718556084552965412665408530614344431858676975145661406800700237877659134401712749470420562230538994561314071127000407854733269939081454664645880797270826683063432858785698305235808933065757406795457163775254202114955761581400250126228594130216471550979259230990796547376125517656751357517829666454779174501129961489030463994713296210734043751895735961458901938971311179042978285647503203198691514028708085990480109412147221317947647772622414254854540332157185306142288137585043063321751829798662237172159160771669254748738986654949450114654062843366393790039769265672146385306736096571209180763832716641627488880078692560290228472104031721186082041900042296617119637792133757511495950156604963186294726547364252308177036751590673502350728354056704038674351362222477158915049530984448933309634087807693259939780541934144737744184263129860809988868741326047215695162396586457302163159819319516735381297416772947867242292465436680098067692823828068996400482435403701416314965897940924323789690706977942236250822168895738379862300159377647165122893578601588161755782973523344604281512627203734314653197777416031990665541876397929334419521541341899485444734567383162499341913181480927777103863877343177207545654532207770921201905166096280490926360197598828161332316663652861932668633606273567630354477628035045077723554710585954870279081435624014517180624643626794561275318134078330336254232783944975382437205835311477119926063813346776879695970309833913077109870408591337464144282277263465947047458784778720192771528073176790770715721344473060570073349243693113835049316312840425121925651798069411352801314701304781643788518529092854520116583934196562134914341595625865865570552690496520985803385072242648293972858478316305777756068887644624824685792603953527734803048029005876075825104747091643961362676044925627420420832085661190625454337213153595845068772460290161876679524061634252257719542916299193064553779914037340432875262888963995879475729174642635745525407909145135711136941091193932519107602082520261879853188770584297259167781314969900901921169717372784768472686084900337702424291651300500516832336435038951702989392233451722013812806965011784408745196012122859937162313017114448464090389064495444006198690754851602632750529834918740786680881833851022833450850486082503930213321971551843063545500766828294930413776552793975175461395398468339363830474611996653858153842056853386218672523340283087112328278921250771262946322956398989893582116745627010218356462201349671518819097303811980049734072396103685406643193950979019069963955245300545058068550195673022921913933918568034490398205955100226353536192041994745538593810234395544959778377902374216172711172364343543947822181852862408514006660443325888569867054315470696574745855033232334210730154594051655379068662733379958511562578432298827372319898757141595781119635833005940873068121602876496286744604774649159950549737425626901049037781986835938146574126804925648798556145372347867330390468838343634655379498641927056387293174872332083760112302991136793862708943879936201629515413371424892830722012690147546684765357616477379467520049075715552781965362132392640616013635815590742202020318727760527721900556148425551879253034351398442532234157623361064250639049750086562710953591946589751413103482276930624743536325691607815478181152843667957061108615331504452127473924544945423682886061340841486377670096120715124914043027253860764823634143346235189757664521641376796903149501910857598442391986291642193994907236234646844117394032659184044378051333894525742399508296591228508555821572503107125701266830240292952522011872676756220415420516184163484756516999811614101002996078386909291603028840026910414079288621507842451670908700069928212066041837180653556725253256753286129104248776182582976515795984703562226293486003415872298053498965022629174878820273420922224533985626476691490556284250391275771028402799806636582548892648802545661017296702664076559042909945681506526530537182941270336931378517860904070866711496558343434769338578171138645587367812301458768712660348913909562009939361031029161615288138437909904231747336394804575931493140529763475748119356709110137751721008031559024853090669203767192203322909433467685142214477379393751703443661991040337511173547191855046449026365512816228824462575916333039107225383742182140883508657391771509682887478265699599574490661758344137522397096834080053559849175417381883999446974867626551658276584835884531427756879002909517028352971634456212964043523117600665101241200659755851276178583829204197484423608007193045761893234922927965019875187212726750798125547095890455635792122103334669749923563025494780249011419521238281530911407907386025152274299581807247162591668545133312394804947079119153267343028244186041426363954800044800267049624820179289647669758318327131425170296923488962766844032326092752496035799646925650493681836090032380929345958897069536534940603402166544375589004563288225054525564056448246515187547119621844396582533754388569094113031509526179378002974120766514793942590298969594699556576121865619673378623625612521632086286922210327488921865436480229678070576561514463204692790682120738837781423356282360896320806822246801224826117718589638140918390367367222088832151375560037279839400415297002878307667094447456013455641725437090697939612257142989467154357846878861444581231459357198492252847160504922124247014121478057345510500801908699603302763478708108175450119307141223390866393833952942578690507643100638351983438934159613185434754649556978103829309716465143840700707360411237359984345225161050702705623526601276484830840761183013052793205427462865403603674532865105706587488225698157936789766974220575059683440869735020141020672358502007245225632651341055924019027421624843914035998953539459094407046912091409387001264560016237428802109276457931065792295524988727584610126483699989225695968815920560010165525637567);
    }

// T sigma = 1.0; //0
// T L = 1.0;
// T gamma = 1.0; //1
// T delta = 1.0; //2  
// T mu = 1.0;    //3
// T u0 = 1.0;    //4 


    void set_state(T parameter_p)
    {
        switch(parameter_number_)
        {
            case 0:
                sigma = parameter_p;
                break;
            case 1:
                gamma = parameter_p;
                break;
            case 2:
                delta = parameter_p;
                break;
            case 3:
                mu = parameter_p;
                break;
            case 4:
                u0 = parameter_p;
                break;
        }

    }

    __DEVICE_TAG__ inline T g_func(T x)
    {
        if(sigma > 0)
        {
            return 1.0/(sqrt(2.0*pi()))*exp(-(1.0/2.0)*(x/sigma)*(x/sigma) ); 
        }
        else
        {
            return 1.0/(sqrt(2.0*pi()));
        }
    }

    __DEVICE_TAG__ inline T right_hand_side(T x, T u)
    {
        T num = sinh(u) - g_func(x)*0.5*mu*exp(u);
        T din = (1 + 2.0*gamma*sinh(u/2.0)*sinh(u/2.0) );
        return num/din;

    }

    __DEVICE_TAG__ inline T right_hand_side_linearization(T x, T u)
    {
        T num = (2.0*(gamma + cosh(u) - gamma*cosh(u)) + (exp(u)*(-1.0 + gamma) - gamma)*mu*g_func(x));
        T din = 2.0*(1.0 - gamma + gamma*cosh(u))*(1.0 - gamma + gamma*cosh(u));
        return num/din;
    }


    __DEVICE_TAG__ inline T right_hand_side_parameter_derivative_sigma(T x, T u)
    {
        // printf("sigma = %e\n", sigma);
        if(sigma > 0)
        {
            return -((exp(u-x*x/(2.0*sigma*sigma))*x*x*mu)/(2.0*sqrt(2.0*pi())*sigma*sigma*sigma*(1.0+2.0*gamma*sinh(0.5*u)*sinh(0.5*u))));
        }
        else
        {
            return -0.0;
        }
    }
    __DEVICE_TAG__ inline T right_hand_side_parameter_derivative_gamma(T x, T u)
    {
        return -((2*sinh(u/2)*sinh(u/2)*(-((exp(u-x*x/(2*sigma*sigma))*mu)/(2*sqrt(2*pi())))+sinh(u)))/((1+2*gamma*sinh(u/2)*sinh(u/2))*(1+2*gamma*sinh(u/2)*sinh(u/2))));
    } 
    
    __DEVICE_TAG__ inline T right_hand_side_parameter_derivative_delta(T x, T u)
    {
        return 1;
    } 
    __DEVICE_TAG__ inline T right_hand_side_parameter_derivative_mu(T x, T u)
    {
        return -(exp(u-x*x/(2*sigma*sigma))/(2*sqrt(2*pi())*(1+2*gamma*sinh(u/2)*sinh(u/2))));
    }  
    __DEVICE_TAG__ inline T right_hand_side_parameter_derivative_u0(T x, T u)
    {
        if(parameter_number_ == 4)
            return 1;
        else
            return 0;
    }               
// T sigma = 1.0; //0
// T L = 1.0;
// T gamma = 1.0; //1
// T delta = 1.0; //2  
// T mu = 1.0;    //3
// T u0 = 1.0;    //4 

    __DEVICE_TAG__ inline T right_hand_side_parameter_derivative(T x, T u)
    {
        switch(parameter_number_)
        {
            case 0:
                return right_hand_side_parameter_derivative_sigma(x, u);
                break;
            case 1:
                return right_hand_side_parameter_derivative_gamma(x, u);
                break;
            case 2:
                return right_hand_side_parameter_derivative_delta(x, u);
                break;      
            case 3:
                return right_hand_side_parameter_derivative_mu(x, u);
                break;                                    
            case 4: // u0
                return 0;
                break;              
        }
        return 0;
    }

    void rotate_initial_function()
    {
        which++;
        which = (which)%3;
    }

    __DEVICE_TAG__ inline T initial_function(T x)
    {
        if (which == 0)
            return u0*exp(-x);
        else if (which == 1)
            return u0*exp(-x*x);
        else
            return (u0/(x*x+1.0));
    }

    __DEVICE_TAG__ inline T exact_solution_uxx(T x)
    {
        T th = sinh(0.25*u0)/cosh(0.25*u0);
        T thexp = th*exp(-x);
        T num = 1+thexp;
        T din = 1-thexp;
        return 2*log(num/din);
    }

    __DEVICE_TAG__ inline T point_in_basis(size_t j)
    {
        // will return Chebysev points only for 1<=j<=N-3
        // other points will be incorrect! beacuse we use 3 boundary conditions.
        return pi()*(2.0*j - 1.0)/(2.0*(N-3) );
    }
    __DEVICE_TAG__ inline T point_in_domain(size_t j)
    {
        auto t_point = point_in_basis(j);
        return from_basis_to_domain(t_point);
    }

    __DEVICE_TAG__ inline T from_basis_to_domain(T t)
    {
        T ss = sin(0.5*t);
        T cs = cos(0.5*t);
        T ss2 = ss*ss;
        T cs2 = cs*cs;
        if(ss2 == 0)
        {
            return compute_infinity<T>();
        }
        T ret = L*cs2/ss2; 
        return ret;
    }
    __DEVICE_TAG__ inline T from_domain_to_basis(T x)
    {
        if(x == 0)
        {
            return pi();
        }
        T y = 1/x;
        T ret = 2*atan(sqrt(L*y));
        return ret;
    }
    __DEVICE_TAG__ inline T from_basis_to_domain_differential(T t)
    {
        //-L Cot[x/2] Csc[x/2]^2=-L Cos[x/2]/(Sin[x/2]^3)
        T ss = sin(0.5*t);
        T cs = cos(0.5*t);
        T ss3 = ss*ss*ss;
        if(ss3 == 0)
        {
            return compute_infinity<T>();
        }
        return -L*cs/ss3;
    }
    __DEVICE_TAG__ inline T* quadrature_points(T x_max, T x_min)
    {
        auto x_len = 0.5*(x_max-x_min);
        auto x_mid = 0.5*(x_max+x_min);
        
        T absc[5];
        T ss1 = sqrt(static_cast<T>(10.0)/static_cast<T>(7.0));

        absc[0] = -1.0/3.0*sqrt(5.0+2.0*ss1);
        absc[1] = -1.0/3.0*sqrt(5.0-2.0*ss1);
        absc[2] = 0;
        absc[3] = 1.0/3.0*sqrt(5.0-2.0*ss1);
        absc[4] = 1.0/3.0*sqrt(5.0+2.0*ss1);


        T points[5];
        #pragma unroll
        for(char jj=0;jj<5;++jj)
        {
            points[jj] = x_len*absc[jj]+x_mid;
        }
        return points;
    }
    __DEVICE_TAG__ inline T* quadrature_wights()
    {
        T wights[5];
        T sqrt70 = static_cast<T>(70.0);
        wights[0] = (322.0-13.0*sqrt70)/900.0;
        wights[1] = (322.0+13.0*sqrt70)/900.0;
        wights[2] = 128.0/255.0;
        wights[3] = (322.0+13.0*sqrt70)/900.0;
        wights[4] = (322.0-13.0*sqrt70)/900.0;
        return wights;
        
    }
    __DEVICE_TAG__ inline T psi(int n, T t)
    {
        return cos(n*t);
    }
    __DEVICE_TAG__ inline T dpsi(int n, T t)
    {
        return -n*sin(n*t);
    }
    __DEVICE_TAG__ inline T ddpsi(int n, T t)
    {
        return -n*n*cos(n*t);
    }
    __DEVICE_TAG__ inline T dddpsi(int n, T t)
    {
        return n*n*n*sin(n*t);
    }
    __DEVICE_TAG__ inline T ddddpsi(int n, T t)
    {
        return n*n*n*n*cos(n*t);
    }
    __DEVICE_TAG__ T ddpsi_map(int l, T t)
    {
        T sn = sin(t/2.0);
        T tn = tan(t/2.0);
        T sin2 = sn*sn;
        T tan3 = tn*tn*tn;
        return 1.0/(2.0*L*L)*sin2*tan3*((2.0 + cos(t))*dpsi(l, t) + sin(t)*ddpsi(l, t));
    }
    __DEVICE_TAG__ T ddddpsi_map(int l, T t)
    {
        T sn = sin(t/2.0);
        T tn = tan(t/2.0);
        T sin2 = sn*sn;
        T tan7 = tn*tn*tn*tn*tn*tn*tn;
        T common = 1.0/(16.0*L*L*L*L)*sin2*tan7;
        T p1 = 3.0*(32.0 + 29.0*cos(t) + 8.0*cos(2.0*t) + cos(3.0*t))*dpsi(l, t);
        T p2 = (91.0 + 72.0*cos(t) + 11.0*cos(2.0*t))*ddpsi(l, t);
        T p3 = (6.0*(2.0 + cos(t))*dddpsi(l, t) + sin(t)*ddddpsi(l, t));
        return common*(p1+sin(t)*(p2 + 2*sin(t)*p3));
    }
    __DEVICE_TAG__ T dddpsi_map_at_zero(size_t k)
    {
        T m1degk = (k%2==0?1.0:-1.0);//(-1)**k;
        return -(4.0/(15.0*L*L*L))*m1degk*(1.0*k*1.0*k)*(23.0 + 20.0*k*k + 2*k*k*k*k);
    }

    T L, gamma, mu, u0, sigma, delta;
    size_t N;
    char which;
    const T delta_threshold = 0.001;
    int parameter_number_;
};

}

#endif