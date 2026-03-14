#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <stdio.h>
static struct pam_conv conv = { misc_conv, NULL };

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: pamtester <pam_config> <username>\n");
    }

    pam_handle_t *pamh;
    int r;

    if ((r = pam_start(argv[1], argv[2], &conv, &pamh)) != PAM_SUCCESS) {
        fprintf(stderr, "start failed: %d\n", r);
    }
    else if ((r = pam_authenticate(pamh, 0)) != PAM_SUCCESS) {
        fprintf(stderr, "authenticate failed: %d\n", r);
    }
    else if ((r = pam_acct_mgmt(pamh, 0)) != PAM_SUCCESS) {
        fprintf(stderr, "acct_mgmt failed: %d\n", r);
    }
    else if ((r = pam_end(pamh, r)) != PAM_SUCCESS) {
        fprintf(stderr, "end failed: %d\n", r);
    }
    else {
        fprintf(stdout, "Authentication successful.\n");
    }
}
