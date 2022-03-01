#include "../playfair.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


extern char* playfair_encrypt(const char* key, const char* text);
extern char* playfair_decrypt(const char* key, const char* text);

const char long_key[30][5000] = {
        "Kral bol velmi vyteseny a oddal dceru svoju jej opravdivemu osloboditelovi","Ked mu to tak dakolko raz opakovala on sa nahneva a zahucka svoje zvierata do nej ale tie sa nepohynali z miesta lebo od toho pruta skameneli obrati sa k nim ale vtom ho striga prutikom posibala a on naraz tiez tam skamenel","Nas suhaj sa poobliekal a siel do palaca aj so svojimi zvermi","Ako to nas suhaj pocul hned dostal chut na hrdo zatovstvo a povedal ze on chce toho draka zabit ak len bude moct","Bratia tito vo vsetkom pekne sa rovnali a matka by ich nebola dala za siry svet","Tu hned zacali znasat zita muky strovy omasty dreva aby vsetkeho na tri roky bolo dost","Ach poveda kdeze si mi tak dlho ako tazko za tebou cakam","Zobrali sa ze sa vratia domov","My ale vam darujeme vsetko nase bohatstvo a pod vasou opatrnostou chceme zivot nas dokoncit ","A pritom hned na slaninu mast zo zaby kvapkala hned mu ju cez usta pretahovala","Hodili im po kusku slaniny s chlebom medvedi sa prestali trhat a sli za bratmi ku samemu domu kde ich do mastale zatvorili","A takto uz viete vsetko co sa stalo ako sa stalo a ako sa malo a muselo stat","Neborka matka plakala den i noc a vsetky kuty vyoblievala slzami","Ked uz boli nedaleko diery kazal kocisovi zastat","Striga zisla dolu doniesla na drevci napichnutu zabu a zacala ju obracat","Pride medved do dvora tu hned vsetci psi a kopovy zacnu do neho brechat ale on si len stupal ticho dalej len ked vacsmi do neho dodievali zlozil kosik a rozohnal havkacov vratil sa pre kosik a vosiel do tej samej izby kde pri stole sedeli pani a hodovali","Vybral sa i on na polovacku a vsetkym cinom sa mu s tou liskou vodilo ako jeho bratovi lenze tento mladsi brat nezaklial","Ty pecies slaninu ja peciem zabu mne bude slanina a tebe zaba","Ved by som sa isla ale sa tych tvojich zverov bojim na ti tento prutik posibaj ich potom zidem ","implanted","flashback","pacific","knotted","convoys","ester"};

const char long_text[30][5000] = {
        "Ako ho ludia zazreli pochytali druky a on v strachu zachytil sa nazad","Ako kocis medveda zazrel hned tri hlavnice spopod neho vypadli","Hned sa aj so zvermi pobral do palaca a rovno stupal do tej izby kde hodovali","Zima mi zima mi","Pod jednym dubom zastal a ze bol lacny nakladol si ohna a zacal si slaninku piect","No ty si sprostak povie lev bez ty medved a dones tu zelinku","Tu princezka musela vyrozpravat vsetko a suhaj na dosvedcenie toho ukazal jazyky z draka","On len pocuva a nic na to nepovie ale ho ta hora mrzela","Pytaj od neho polovicku z tej zeliny a ak by ti podobrotky nechcel dat vezmi mu nasilu","Tu sa mily lev rozbehne vyskoci drakovi na chrbat a mocnymi pazurmi vsetkych osem hlav aj s krkom od hnusneho tela odtrhol","On sa obzrie a vidi na strome jednu skrcenu staru babu sediet","V jedno rano ako ho mladenec obliekal vyzrel von oblokom a tu na jednej strane videl krasne zelene hory na druhom boku ale bola hora smutna ozltnuta ako v jesen","Suhaj nelenivy odfrkla drakovi hlava","Ked ti zima pod sa zohriat ten tu dolu povie a na to ostalo ticho","O mesiac sa dostal zase do toho mesta a teraz ho videl cervenym suknom obtiahnuto","Medved sa rozbehol a trafil tiez na tie vozy ale ked furmani videli medveda pokryli sa do vozov ako mysi do diery pred mackou","Brat moj povie starsi na medzi sme tu sa musime rozlucit","Ide ide aj so svojimi zvermi ide hustymi horami krasnymi polami az sa dostal do toho palaca kde sa jeho brat bol prizenil","Co je to ze vsetky hory naokolo su tak pekne rozvite a len ta jedna je taka ozltnuta","Od velxxxo zialu zrevali a zavyjali strasne","Na treti den pohotowe nezabili nic len dwoch lewow co sa medzi sebou driapali upokojili a dowiedli domow","Zvixxata stali na boku a lizali svojich skamenenych bratov","Ked uz bola noc a isli si polihat mladsi brat medzi seba a bratowu zenu zabodol do postele mec","Ale ako suhaji dorastli a videli ze druhi do sveta odchadzaju zacalo aj ich von z domu tahat a povedali matkxxxe sa chcu do sveta podivat","Nic sme poweda nezastrelili ale sme dowiedli dwoch wlkow a do mastale sme ich zatworili " };

const char long_text_output[30][5000] = {
        "LR VG MK FT EB QB HB MA MF YG GT SR BM TB CR SK MY ET UV KJ RH QB UG TS MB JE SL QB NZ","TD TE PG YN UD AJ DM TV TV OU TI PM KA LY IT VJ IQ GO ZV PC AE PM CT SJ VO MA YQ","NA KC US NP OK RM DM VE OB DX HP KB EP PH EH UM JZ SJ OS AB HP KB QK IV RO TC CK SL KB MN JC","VM ZN ZM VM ZN ZM","MV HQ SZ LM NC GT MC DT EA TN TD OT EM NT DM ML IS NT CS NE BK DP IQ TD BD TN KA EN SD AY EX YR OZ IU","UB EI MS MJ OV IU CM JV RM LY HF FN DU IK TL FH ZC ZR ET IU ZS LY KT SN","IG HX SQ EI VZ HS BI ZI VS NX ZL HX VS PS SB KI ZP VB FC OB AV ZH BS DK EI QS KI AP CJ VP VO JY OV XZ OL MH PV PN","AH IV GY RD YS RY VY ED YV DZ KV QZ LS VR IV QI FZ QI AZ CB RL VZ","HA KY UN JT YZ KC CU SU QB OR HN JN XJ MQ TE EG RP HM SF CK UT PV NK TA ZJ ZP ZL YU YK JM BE MV JO MK QM JQ","IZ DP NP SK ZH KI ED JO NE NJ FY BH QA LA RB NB NU OA LH CO AP HM QO FS TR TD LI NP YU ZE VK GO MD OH LK IB TB LY HG MH DB NE ZL EO NM EZ DR DB AI NM ZG","PV ME HV BT LC NB LI OC EM ZT HP YX YL CP MU TY AY SM BC TK FB TM EZ IL CZ","EG SB JU PK JU TO KJ KB CT BS JS BA DM ES OT GL PS XI GL UJ EJ BT OU CK KA FU XB NY BX VU PK JS IE BS MT PK DY SV VB SJ IJ KX UY UC YK JK BD UO AT BV JE CT JK PK ID AK FU AE GV YS KT TO TE XB ZS JY","YZ ED GB ND BE CL ZE VY NP DK VE MA RC DJ DK DP","ED EF NU OQ YJ LE AR EN TS BC HM MO OH ZU LI DQ BT OU SB RV NM NR VR IL GO SG NM","ZY UR SD UG ZO AG SZ DL UA VL ZG ZF ZY UR SZ ZS BL ZL FZ JD LV OE BL CV CM KT PS CZ YZ HR SD MH NS DY","TP RA PE BS IV BL RC TZ TM DV GR XC DP GZ TM DP OA BZ TB PL PE JH PV OS RO DE TX PO PE TR AS IM YP ZK DN SA AO NG AO MB AV BH DE AI DP VF RI PE VT UL MN","RA VH JS TU LR NK LM VA IO EN HC TG OI HC JP NY JC IO HC OU VP EK LD","UO TA HT SZ IQ AQ QU LU AU EA PG NO UO AV JI YP UL DV VL UL GX NL SC UL TR AN UL ZH LN OT IY NA OT IT DV EL AN EN DF YA SZ AV XU VL CU RI LP AU CA SA","TM TY RT RV SL OR XV TA UE PM SF ST MO RJ SQ RB GZ OF SR YS RO SH DR HO TY MG IH OR SQ IM KZ CR RJ IQ","RT XT PY PP SV MI IY YS TX IA MI AB XZ SB AM OB SL KB GP","JH OT NZ MC NT QP FT OP ZC TN XH CG CP GJ IC NT CY PB FA CZ PU BP HS ND EY ML BC UF MY JL QL CP VO QB QG PC JL BR LP BE CP BR GR XY","UX CY VC QF TO CK FM PD QJ VP MC VF MC QY UO FI GT QD LG LH MZ FE EO FQ QU","NK GK XF EI HA TB BH ZS LQ HQ EI JI CN SG BA QL CQ CN SK FU LQ OF BV BC PC ET XV EF KV VF IB BK GF NQ EQ EK SF SK BY","GT SB LC BR GB FJ AV TS AR PG DO PI AQ JX SE TX IJ AV DC AZ GA SV GB EX EG XR SO GT AG FJ NF YN YU AV UN OG GB OG LV YD EB PG LB RL VV ZD AB NF NR AV DC AZ DL VA PD GO","VN IC UB QP US GT MS AG TR AS HJ HJ GQ ST UB JX SN TB HJ CX ND IU HL NX TG PN ET RE HA EN SH BI AG SX PT JH JV"
};

const char short_key[50][5000] = {
        "womanize","assorted","bloody","feedings","sunshine","unaccented","firewoods","arsons","unbarred","infantries","chinking","praetor","scissors","banker","produce","occupies","winging","inlaid","bongos","eked","implanted","flashback","pacific","knotted","convoys","ester","subsisted","peek","unfurls","pranked","hulking","wobbling","egret","fixedly","winches","chunk","punctuated","bluster","openings","cohorts"
};

const char short_text[50][5000] = {
        "ministries","slurs","fungi","primped","delft","midi","tartar","clattering","madrigals","bindings","darlings","yearns","sentinels","sheltie","drilling","finns","crony","regulars","mongol","abasing","bxxxekly","tropics","proxxed","announces","lecixxxns","membrane","barmxxds","wats","contraxxo","condor","cuxxxe","amplifying","fomexxed","steal","teaxxoms","toggled","mxxxier","hungerless","fxxxtives","decorous"
};

const char short_text_output[50][5000] = {
        "VE VC TU KC IU","AM YA OV","CX SA KU","QT NL VS AD","EA FG VY","OH IO","YO FX SE","BM NL QF SH AK","QU GN LD RK PZ","RA IG NF HE","EB XR NK DP","ED EA QL","OA PM CP FK IU","OL KM PM NZ","UO GN NG LI","KO XU MA","EP QV ZY","XK BZ AD ST","PB GS SI","BE HY HO MD","EZ PP NQ DL","OT PQ PI AY","CO RU CL EV","HA OT VK FT QZ","QA VF VV UV DR","UB UH AE MS","AJ SR BB EU","YE OT","BP UV NC FF XF","DS RC VD","GI LL VF","NQ RO OK ZL GA","CQ IA RR RB","TU XB AF","VF JN UP OE","CT JT IM FE","OV NN HD OZ","NA MH RA BR UY UY","HV EE ZC XP AV","ES OH TH CF"
};

void playfair_encrypt_dry_run()
{
    printf("Tests playfair_encrypt_dry_run:\n");

    assert(playfair_encrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_decrypt_dry_run()
{
    printf("Tests playfair_decrypt_dry_run:\n");

    assert(playfair_decrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_encrypt_key_isalpha()
{
    printf("Tests playfair_encrypt_key_isalpha:\n");

    assert(playfair_encrypt("#$%&'()*", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_decrypt_key_isalpha()
{
    printf("Tests playfair_decrypt_key_isalpha:\n");

    assert(playfair_decrypt("#$%&'()*", "abc") == NULL);


    printf("Tests passed.\n");
}


void playfair_encrypt_short_text()
{
    printf("Tests playfair_encrypt_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        char* encrypted = playfair_encrypt(short_key[i], short_text[i]);
        assert(strcmp(encrypted, short_text_output[i]) == 0);
        free(encrypted);
    }

    printf("Tests passed.\n");
}

void playfair_decrypt_short_text()
{
    printf("Tests playfair_decrypt_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        char* decrypted = playfair_decrypt(short_key[i], short_text_output[i]);
        assert(strcmp(decrypted, short_text[i]) == 0);
        free(decrypted);
    }

    printf("Tests passed.\n");
}

void playfair_encrypt_long_text()
{
    printf("Tests playfair_encrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        char* encrypted = playfair_encrypt(long_key[i], long_text[i]);
        assert(strcmp(encrypted, long_text_output[i]) == 0);
        free(encrypted);
    }

    printf("Tests passed.\n");
}

void playfair_decrypt_long_text()
{
    printf("Tests playfair_decrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        char* decrypted = playfair_decrypt(long_key[i], long_text_output[i]);
        assert(strcmp(decrypted, long_text[i]) == 0);
        free(decrypted);
    }

    printf("Tests passed.\n");
}

int main()
{
    printf("Tests for playfair.c:\n");
//    TODO: Implement memory leak check
//    printf("Memory check:\n");

    printf("Tests for encrypt:\n");
    playfair_encrypt_dry_run();
    playfair_encrypt_key_isalpha();
    playfair_encrypt_short_text();
    playfair_encrypt_long_text();

    printf("Tests for decrypt:\n");
    playfair_decrypt_dry_run();
    playfair_decrypt_key_isalpha();
    playfair_decrypt_short_text();
    playfair_decrypt_long_text();

    printf("Tests passed.\n");
    return 0;
}
