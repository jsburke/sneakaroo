#include <stdio.h>
#include <stdbool.h>
#include <sys/ptrace.h>

bool is_debugger_attached(){
  return (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1);
}

int main(){
  if(is_debugger_attached()){
    printf("I can see the debugger\n");
  } else {
    printf("The debugger is a lie\n");
  }
}
