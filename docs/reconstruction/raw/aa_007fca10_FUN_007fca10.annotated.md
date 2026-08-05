# Annotated low-level: FUN_007fca10

| Field | Value |
|---|---|
| Stable ID | `aa_007fca10` |
| VA | `0x007fca10` |
| System | `missions-progression` (generic UI close host; mission Flush invoker) |
| Date | `2026-07-29` (wave3 dual strengthen — UF-010) |
| Prior scaffold | `2026-07-23` |

## Machine-level notes

- Source: raw capture `aa_007fca10` + live re-decompile 2026-07-29 (identical body).
- Register convention (decompiler): **`EAX`** = UI/dialog object to close; **`EBX`** = client host.
- Prefer assembly when decompiler conflicts; body is small and settled.
- **Leave-FUN:** no string/RTTI → keep `FUN_007fca10` (do not invent product name).
- Informal chain alias: "CloseVisibleDialog" / "Flush invoker host" — documentation only.

## Role in C2S 0x206E (UF-010)

This is the **generic host that invokes virtual slot `vtbl+0x440`** on a visible dialog. For the NPC mission dialog (`client+0x1058`, vtable base `0x00a4a51c`), that slot is `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` (DATA `0x00a4a95c`).

```
FUN_008aec40 / FUN_008af020  (dialog UI event)
  → FUN_007fca10              (this unit)
      if visible (vtbl+0x3d8):
        call vtbl+0x440       → FlushPreparedResponse (mission class)
```

**Not** invoked by `Client_HideMissionDialogIfOpen` (`+0x107c`).

## Sealed control flow (when Flush is called)

| Step | Condition / action | Offset / slot |
|---|---|---|
| G0 | `*(client+0xf40) != 0` AND `dialog (EAX) != null` | host gates |
| G1 | `dialog.vtbl+0x3d8()` returns non-zero | **visible / live** |
| **F** | **`dialog.vtbl+0x440()`** | **Flush for mission dialog** |
| D1 | If `**(client+0xf40) != 0`: parent `vtbl+0xb0()` | detach / notify |
| S1 | Scan table `client+0x1030` for `i=0..0x39`, **skip `i==0x16`** | dialog slots |
| S2 | For each slot: non-null, `vtbl+0x3d8` live, and `obj[0x140]==1` → goto tail (skip restore) | exclusive-modal check |
| R1 | Else if `client+0xf38` non-null: call `(*+0xf38).vtbl+0x3c4(flag)` | UI restore |
| T1 | If `*(client+0x10b0)` and `*(that+0x664)`: call `(*+0x664).vtbl+0x47c` | optional tail |

**Critical:** Flush (`+0x440`) runs **before** table scan / restore. Visibility gate is the only dialog-side precondition for Flush.

## Mission-dialog specialisation

| Item | Value | Confidence |
|---|---|---|
| Host field | `client+0x1058` | High |
| Table index | `(0x1058-0x1030)/4 = **10**` | High |
| Vtable base | `0x00a4a51c` (ctor `FUN_008ac3f0`) | High |
| Slot `+0x440` | DATA `0x00a4a95c` → dword **`0x008ab8f0`** | High (`read_memory`) |
| Visible slot | `+0x3d8` (shared UI predicate pattern) | High (call site); semantics Probable |

## Mission-path callers (static)

| Caller | VA | When it calls this |
|---|---|---|
| `FUN_008aec40` | `0x008aec40` (call site `0x008aef96`) | Response btn `0x9c46..0x9c4d` + msg 8 after `HandleButton` success; **or** close `case 40000` (`0x9c40`) + msg 8 **without** fill |
| `FUN_008af020` | `0x008af020` | `HandleButton(0)` success → this |
| Many others | (100+ xrefs) | Generic close any UI object in EAX — **not** mission-specific |

## UF-011 (cancel / stale 0x206E)

- This function **never** reads or clears `dialog+0x650`.
- Close path (`0x9c40` → this → `+0x440`) can still flush prepared opcode from show-time Prepare.
- Ownership of clear is **Flush** / Prepare / HandleButton — **not** this host. Residual stays on `aa_008ab8f0` / UF-011.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fca10(void)
// EAX = dialog/UI*; EBX = client host*
{
  int *piVar1;
  char cVar2;
  int *in_EAX;      // dialog to close
  int unaff_EBX;    // client
  int *piVar3;
  int iVar4;
  undefined1 uVar5;
  
  // G0: parent + dialog present
  if ((*(int *)(unaff_EBX + 0xf40) != 0) && (in_EAX != (int *)0x0)) {
    // G1: visible?
    cVar2 = (**(code **)(*in_EAX + 0x3d8))();
    if (cVar2 != '\0') {
      // F: virtual close/flush slot — mission dialog → FlushPreparedResponse
      (**(code **)(*in_EAX + 0x440))();
      // D1: parent detach
      if (**(int **)(unaff_EBX + 0xf40) != 0) {
        (**(code **)(*(int *)**(int **)(unaff_EBX + 0xf40) + 0xb0))();
      }
      // S1/S2: another exclusive-visible dialog still up?
      iVar4 = 0;
      piVar3 = (int *)(unaff_EBX + 0x1030);
      do {
        if ((iVar4 != 0x16) && (piVar1 = (int *)*piVar3, piVar1 != (int *)0x0)) {
          cVar2 = (**(code **)(*piVar1 + 0x3d8))();
          if ((cVar2 != '\0') && (piVar1[0x140] == 1)) goto LAB_007fcac1;
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < 0x3a);
      // R1: restore UI chrome if no exclusive dialog remains
      if (*(int **)(unaff_EBX + 0xf38) != (int *)0x0) {
        if (*(char *)(unaff_EBX + 0x31d9) == '\0') {
          *(undefined1 *)(unaff_EBX + 0x31d8) = 1;
          uVar5 = 1;
        }
        else {
          uVar5 = *(undefined1 *)(unaff_EBX + 0x31d8);
        }
        (**(code **)(**(int **)(unaff_EBX + 0xf38) + 0x3c4))(uVar5);
      }
LAB_007fcac1:
      // T1: optional secondary object callback
      iVar4 = *(int *)(unaff_EBX + 0x10b0);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x664) != 0)) {
        (**(code **)(**(int **)(iVar4 + 0x664) + 0x47c))();
        return;
      }
    }
  }
  return;
}
```

## Open questions

1. Exact product name of `vtbl+0x3d8` (IsVisible?) — pattern only; leave unnamed.
2. Semantic of table index skip `0x16` and field `obj[0x140]==1` (exclusive/modal flag?) — Probable.
3. Full semantics of `+0xf40` / `+0xf38` / `+0x10b0` parent objects — out of UF-010 scope.
4. Runtime: confirm EAX is always mission dialog at `+0x1058` on accept path (static dispatch chain says yes via event handlers on that dialog).
5. UF-011 clear-before-flush remains open on Flush / Prepare side.
