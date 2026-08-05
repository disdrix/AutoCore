# Raw capture: FUN_007fbbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbbb0` |
| **Canonical name** | `FUN_007fbbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbbb0(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x113c) != 0) {
    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x113c) + 0xd0))();
    if ((cVar2 != '\0') && (*(int *)(*(int *)(unaff_ESI + 0x113c) + 0x2b0) != 0)) {
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0xb0))
                (*(int *)(unaff_ESI + 0x113c));
      (**(code **)(**(int **)(unaff_ESI + 0x113c) + 4))(0);
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x1c8))(0);
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x3c0))(0);
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x514)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(undefined4 *)(iVar1 + 0x498) = *(undefined4 *)(iVar1 + 0x514);
      }
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x518)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(undefined4 *)(iVar1 + 0x49c) = *(undefined4 *)(iVar1 + 0x518);
      }
    }
  }
  return;
}
```

---

## Live re-verify (2026-07-29 wave8 OWN-ONLY dual)

| Check | Result |
|---|---|
| Ghidra `force_decompile` + `decompile_function` | Body **=** capture above |
| Body range | `0x007fbbb0`–`0x007fbc6a` |
| `read_memory` offsets | `0x113c`, `0xf40`, `0xd0`, `0x2b0`, `0xb0`, `0x1c8`, `0x3c0`, `0x514`?`0x498`, `0x518`?`0x49c` |
| P-code ESI | `register:0x18` + host loads |
| Xrefs | 11 UNCONDITIONAL_CALL (Grab FromGrid/Hardpoint + shared UI) |
| Duals | `reviews/A_aa_007fbbb0_FUN_007fbbb0.md`, `reviews/B_aa_007fbbb0_FUN_007fbbb0.md` |
