#ifndef KEYBOARD_LAYOUT_HYPR_IPC_H
#define KEYBOARD_LAYOUT_HYPR_IPC_H

#include <stdint.h>
#include <sys/un.h>

struct hypr_ipc {
  struct sockaddr_un control_address;
  struct sockaddr_un event_address;
};

int hypr_ipc_init(struct hypr_ipc *ipc, const char *runtime_dir,
                  const char *instance_signature);
int hypr_ipc_connect_events(const struct hypr_ipc *ipc);
int hypr_ipc_active_window(const struct hypr_ipc *ipc, uint64_t *window);
int hypr_ipc_current_layout(const struct hypr_ipc *ipc, int *layout);
int hypr_ipc_device_layout(const struct hypr_ipc *ipc, const char *device,
                           int *layout);
int hypr_ipc_switch_layout(const struct hypr_ipc *ipc, int layout);
int hypr_keyboard_is_typing(const char *device);

int hypr_json_active_window(const char *json, uint64_t *window);
int hypr_json_current_layout(const char *json, int *layout);
int hypr_json_device_layout(const char *json, const char *device, int *layout);

#endif
