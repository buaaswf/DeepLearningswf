#define TRUE 1
#define FALSE 0

FILE *Open_Data_File(char *file_name); //Opens data file
double *Read_Vector(int N, FILE *data_in); //Reads a 1d Vector from file
double LogAdd(double x, double y); //Kingsbury-Rayner formula
template <typename T>
bool NanCheck(const T& x, const T& y); //Return TRUE if there is a NaN
float ModArr(float *array, int N);; //Return array's module 

double *MallocDouble_1d(int n); //Alloc 1d Double
double **MallocDouble_2d(int x, int y); //Alloc 2d Double
double ***MallocDouble_3d(int x, int y, int z); //Alloc 3d Double
double ****MallocDouble_4d(int x, int y, int z, int w); //Alloc 4d Double

void FreeDouble_1d(double *v); //Free 1d Double
void FreeDouble_2d(double **v, int x); //Free 2d Double
void FreeDouble_3d(double ***v, int x, int y); //Free 3d Double
void FreeDouble_4d(double ****v, int x, int y, int z); //Free 4d Double
