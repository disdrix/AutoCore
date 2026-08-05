# Review A (reconstruction fidelity): `aa_0092ce50` Client_HideMissionDialogIfOpen

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce50` |
| **VA** | `0x0092ce50` |
| **Canonical name** | `Client_HideMissionDialogIfOpen` |
| **Review date** | `2026-07-29` (UF-010 contrast re-seal) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_0092ce50_Client_HideMissionDialogIfOpen.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept** — **NOT** Flush invoker (UF-010 contrast sealed High) |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_HideMissionDialogIfOpen.cpp` |
| Live decompile | Ghidra `decompile_function` @ `0x0092ce50` |
| Body bytes | Ghidra `read_memory` 64B @ `0x0092ce50` |
| Xrefs | `0x008aeb7e`, `0x008aec12`, `0x00954652` |
| Flush contrast | `aa_008ab8f0` @ `0x008ab8f0`; invoker `FUN_007fca10` @ `0x007fca10` |
| Flush vtbl slot | DATA `0x00a4a95c` → dword `0x008ab8f0` (`read_memory`) |
| Experiment model | `docs/reconstruction/experiments/mission_dialog_c2s.py` |

**Purpose:** If mission UI root at `client+0x107c` is non-null and visible (`vtbl+0x3d8`), hide it (`vtbl+0x448`) and refresh layout (`vtbl+0x34c` tail-jmp). No packet, no dialog `+0x650`, no Flush.

---

## 2. Body (sealed)

### Pseudocode (Ghidra)

```
// ESI = client / game controller (unaff_ESI)
if (*(client + 0x107c) != 0) {
  if (root->vtbl[+0x3d8]()) {          // IsVisible
    root->vtbl[+0x448]();              // Hide
    root->vtbl[+0x34c]();              // Layout refresh (FFA0 = jmp, not call)
  }
}
```

### Assembly decode (`read_memory` @ `0x0092ce50`)

| Bytes | Instruction | Meaning |
|---|---|---|
| `83 be 7c 10 00 00 00` | `cmp [esi+0x107c], 0` | null check mission UI root |
| `74 2e` | `je ret` | early out |
| `ff 90 d8 03 00 00` | `call [eax+0x3d8]` | visible probe |
| `84 c0` / `74 1c` | `test al,al` / `je` | skip if hidden |
| `ff 92 48 04 00 00` | `call [edx+0x448]` | hide |
| `ff a0 4c 03 00 00` | `jmp [eax+0x34c]` | layout (tail) |
| `c3` | `ret` | only on skip paths |

**No** absolute/relative CALL to `0x008ab8f0` or `0x007fca10`. **No** load of `DAT_00d1b4b8`. **No** `+0x650` / `+0x440` / send `+0x18`.

Callee list: **empty** (all targets are virtual; Ghidra classification **leaf**).

---

## 3. UF-010 contrast (why this is NOT the Flush invoker)

| Dimension | Hide `0x0092ce50` | Flush invoker path (UF-010 sealed) |
|---|---|---|
| Host field | `client+0x107c` | NPC mission dialog `client+0x1058` (table idx 10 from `+0x1030`) |
| Visibility slot | `vtbl+0x3d8` | `vtbl+0x3d8` (same *name*, different object) |
| Action slot | **`+0x448` hide**, **`+0x34c` layout** | **`+0x440` → Flush** `0x008ab8f0` |
| Wire | none | if `dialog+0x650 != 0` send size `0x20` via `DAT_00d1b4b8` vtbl+0x18 |
| Close invoker | this function itself is UI hide only | `FUN_007fca10` → visible → `vtbl+0x440` |
| On dialog class | n/a (wrong host) | class `+0x448` is empty stub `FUN_0056f570` (Hide path would not send even if forced onto dialog object) |

**Sealed claim:** `Client_HideMissionDialogIfOpen` is a **red herring** for UF-010. Real Flush invoker is `FUN_007fca10` (`0x007fca10`) calling **`vtbl+0x440`**.

---

## 4. Callers (static)

| Site | Function | Role |
|---|---|---|
| `0x008aeb7e` | `Client_MissionDialogHandleButton` (`0x008ae7c0`) | After accept/GiveMission branch |
| `0x008aec12` | same | After turn-in CompleteObjective success |
| `0x00954652` | **unnamed** region (no Ghidra function at site) | `E8` rel → `0x0092ce50` confirmed by byte decode |

HandleButton fills `+0x650` payload in state 1 but **does not** send 0x206E; send is Flush via separate close path. Hide here only collapses UI after local mission ops.

---

## 5. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| Root `client+0x107c` | **High** | `cmp [esi+0x107c],0` |
| Visible `vtbl+0x3d8` | **High** | `call [eax+0x3d8]` |
| Hide `vtbl+0x448` | **High** | `call [edx+0x448]` |
| Layout `vtbl+0x34c` (tail jmp) | **High** | `FFA0` not `FF90` |
| **Not** Flush invoker | **High** | no `+0x440`, wrong host, no wire |
| No packet / no `+0x650` touch | **High** | full body 0x37B + padding |
| `unaff_ESI` = client | **High (role)** | field map + sibling reviews; register convention |

---

## 6. Gaps

1. Product name of object at `+0x107c` (missionUiRoot role High; class name open).
2. Exact identity of third caller body containing `0x00954652` (bytes seal CALL target; function name open).
3. Runtime: whether any other path can reach Hide after Prepare without Flush (static: Hide never Flushes; close path Flushes independently).

---

## 7. Files

- Clean: `docs/reconstruction/reconstructed-exact/Client_HideMissionDialogIfOpen.cpp`
- Dual: this file + `B_aa_0092ce50_Client_HideMissionDialogIfOpen.md`
- Contrast: `A/B_aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md`
- Model: `docs/reconstruction/experiments/mission_dialog_c2s.py` (`CLIENT_NPC_DIALOG_FIELD = 0x1058  # not +0x107c`)

**Verdict:** **accept** — UF-010 negative seal (**NOT** Flush invoker).
