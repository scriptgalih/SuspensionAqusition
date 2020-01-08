/*
 * Nilai variabel yang di setting
 * Masukkan batasan-batasan limit sesuai kebutuhan
 */
#define NORMAL_LIMIT     2.8
#define POOR_LIMIT       3.1
#define VERY_POOR_LIMIT  3.45

/*
 * Pin analog
 * Definisikan pin analog sesuai dengan kebutuhan
 * Apabila ingin menambah jumlah suspensi tinggal tambah "#define PIN_SUSPENSI_5 <pin analog>" dan seterusnya
 */
#define TOTAL_SUSPENSION 4
#define PIN_SUSPENSI_1 A0
#define PIN_SUSPENSI_2 A1
#define PIN_SUSPENSI_3 A2
#define PIN_SUSPENSI_4 A3

/*
 * Variabel tidak boleh di otak-atik
 */
bool isAllNormal = false;

String status;

float good_count = 0, poor_count = 0, vpoor_count = 0;
float balance[TOTAL_SUSPENSION];
float average;
char text_lcd[16];
