# Annotated low-level: FUN_008cedd0

| Field | Value |
|---|---|
| Stable ID | `aa_008cedd0` |
| VA | `0x008cedd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cedd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008cedd0(void)

{
  int in_EAX;
  int unaff_ESI;
  char *pcVar1;
  
  if (in_EAX == 0) {
    if (*(int *)(unaff_ESI + 0x6d0) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x3ac))("i_d_fec_2d_btn_class_commando");
    }
    if (*(int *)(unaff_ESI + 0x6d4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x3ac))("i_d_fec_2d_btn_class_engineer");
    }
    if (*(int *)(unaff_ESI + 0x6d8) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x3ac))("i_d_fec_2d_btn_class_lieutenant");
    }
    if (*(int *)(unaff_ESI + 0x6dc) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x3ac))("i_d_fec_2d_btn_class_bountyhunter");
    }
    if (*(int *)(unaff_ESI + 0x6d0) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x308))("Commando");
    }
    if (*(int *)(unaff_ESI + 0x6d4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x308))("Engineer");
    }
    if (*(int *)(unaff_ESI + 0x6d8) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x308))("Lieutenant");
    }
    if (*(int *)(unaff_ESI + 0x6dc) == 0) goto LAB_008cf081;
    pcVar1 = "Bounty Hunter";
  }
  else if (in_EAX == 1) {
    if (*(int *)(unaff_ESI + 0x6d0) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x3ac))("i_d_fec_2d_btn_class_champion");
    }
    if (*(int *)(unaff_ESI + 0x6d4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x3ac))("i_d_fec_2d_btn_class_shaman");
    }
    if (*(int *)(unaff_ESI + 0x6d8) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x3ac))("i_d_fec_2d_btn_class_archon");
    }
    if (*(int *)(unaff_ESI + 0x6dc) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x3ac))("i_d_fec_2d_btn_class_avenger");
    }
    if (*(int *)(unaff_ESI + 0x6d0) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x308))("Champion");
    }
    if (*(int *)(unaff_ESI + 0x6d4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x308))("Shaman");
    }
    if (*(int *)(unaff_ESI + 0x6d8) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x308))("Archon");
    }
    if (*(int *)(unaff_ESI + 0x6dc) == 0) goto LAB_008cf081;
    pcVar1 = "Avenger";
  }
  else {
    if (in_EAX != 2) goto LAB_008cf081;
    if (*(int *)(unaff_ESI + 0x6d0) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x3ac))("i_d_fec_2d_btn_class_terminator");
    }
    if (*(int *)(unaff_ESI + 0x6d4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x3ac))("i_d_fec_2d_btn_class_constructor");
    }
    if (*(int *)(unaff_ESI + 0x6d8) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x3ac))("i_d_fec_2d_btn_class_mastermind");
    }
    if (*(int *)(unaff_ESI + 0x6dc) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x3ac))("i_d_fec_2d_btn_class_agent");
    }
    if (*(int *)(unaff_ESI + 0x6d0) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x308))("Terminator");
    }
    if (*(int *)(unaff_ESI + 0x6d4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x308))("Constructor");
    }
    if (*(int *)(unaff_ESI + 0x6d8) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x308))("MasterMind");
    }
    if (*(int *)(unaff_ESI + 0x6dc) == 0) goto LAB_008cf081;
    pcVar1 = "Agent";
  }
  (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x308))(pcVar1);
LAB_008cf081:
  if (*(int *)(unaff_ESI + 0x6d0) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0xd4))(1);
    (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x34c))();
  }
  if (*(int *)(unaff_ESI + 0x6d4) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0xd4))(1);
    (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x34c))();
  }
  if (*(int *)(unaff_ESI + 0x6d8) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0xd4))(1);
    (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x34c))();
  }
  if (*(int *)(unaff_ESI + 0x6dc) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0xd4))(1);
                    /* WARNING: Could not recover jumptable at 0x008cf117. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x34c))();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
