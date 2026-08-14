#include "keyboard_layout/hypr_ipc.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct hypr_ipc ipc;
  if (hypr_ipc_init(&ipc, getenv("XDG_RUNTIME_DIR"),
                    getenv("HYPRLAND_INSTANCE_SIGNATURE")) != 0) {
    fprintf(stderr, "invalid Hyprland environment\n");
    return EXIT_FAILURE;
  }

  uint64_t window = 0;
  int layout = -1;
  if (hypr_ipc_active_window(&ipc, &window) != 0 ||
      hypr_ipc_current_layout(&ipc, &layout) != 0) {
    fprintf(stderr, "could not read Hyprland state\n");
    return EXIT_FAILURE;
  }

  printf("active window: 0x%llx\nactive layout: %d\n",
         (unsigned long long)window, layout);
}
