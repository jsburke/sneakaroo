#include <stdio.h>
#include <stdbool.h>
#include <sys/ptrace.h>

bool is_debugger_attached(){
  return (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1);
}

bool early_debug = false;

void __attribute__ ((constructor)) premain(){

  if(is_debugger_attached()){
    early_debug = true;
  }

}

int main(){

  if(early_debug){
    printf("debugger found before\n");
  }

  return 0;
}
