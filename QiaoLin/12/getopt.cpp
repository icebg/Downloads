#include <iostream>
#include <cstdlib>
#include <getopt.h>
using namespace std;
const char * program_name;
// 输出程序用法
void OutputInfo( ostream & os, int exit_code ) {
	os << "Usage: " << program_name << " options [filename]" << endl;
	os << " -h --help: Display this usage information." << endl;
	os << " -o --output filename: Write output to file." << endl;
	os << " -v --verbose: Print verbose messages." << endl;
	exit( exit_code );
}
int main( int argc, char* argv[] )
{
	// 全部短选项的合并字符串，“:”表示带有附加参数
	const char * const short_opts = "ho:v";
	const struct option long_opts[] =
	{
		{ "help", 0, NULL, 'h' },
		{ "output", 1, NULL, 'o' },
		{ "verbose", 0, NULL, 'v' },
		{ NULL, 0, NULL, 0 }
	};
	// 参数指定的输出文件名
	const char * output_filename = NULL;
	// 是否显示复杂信息
	int verbose = 0;
	// 保存程序名
	program_name = argv[0];
	// 如果为长选项，第五个参数输出该选项在长选项数组中的索引
	int opt = getopt_long( argc, argv, short_opts, long_opts, NULL );
	while( opt != -1 ) {
		cout <<"next arg index in argv[] to process :"<<optind <<endl;
		switch( opt ) {
			case 'h': // “-h”或“--help”
				OutputInfo( cout, 0 );
			case 'o': // “-o”或“--output”，附加参数由optarg提供
				output_filename = optarg; break;
			case 'v': // “-v”或“--verbose”
				verbose = 1; break;
			case '?': // 用户输入了无效参数
				OutputInfo( cerr, 1 );
			case -1: // 处理完毕
				break;
			default: // 未知错误
				abort();
		}
		opt = getopt_long( argc, argv, short_opts, long_opts, NULL );
	}
	return 0;
}
