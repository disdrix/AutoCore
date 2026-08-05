# Review A (reconstruction fidelity): `aa_008a05a0` UI_HostRefreshBoundChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a05a0` |
| **VA** | `0x008a05a0` |
| **Canonical name** | `UI_HostRefreshBoundChrome_Inferred` (Ghidra `FUN_008a05a0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008a05a0_UI_HostRefreshBoundChrome_Inferred.md` |
| **System** | `client-ui` / char sheet & mission chrome refresh |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High (role).** Small **gated UI refresh** on a dialog host (`this` recovered as EDI):

```c
void FUN_008a05a0(void) {  // this in EDI
  if (*(int *)(this + 0x684) != 0) {
    FUN_008af180(0);
    FUN_008a0370();
    if (*(int *)(this + 0x664) != 0) {
      // vcall: (*(this+0x664))->vtbl[+0x480]()
      (**(code **)(**(int **)(this + 0x664) + 0x480))();
    }
  }
}
```

1. Guard: host slot **`+0x684` non-null** (bound child / panel present).
2. `FUN_008af180(0)` + `FUN_008a0370()` — sibling refresh/prep helpers (not dualled here).
3. If **`+0x664` non-null**, virtual call **`vtbl+0x480`** on that child (refresh/relayout).

---

## 2. Callers (High — UI fan-in)

| Caller | VA |
|---|---|
| `CDlgCharSheet2d_CreateChildWidgets` | `0x008faaf0` |
| `Client_RecvCharacterLevel` | `0x00810f00` |
| `Client_RefreshMissionDialogChrome` | `0x009306a0` |
| `Client_SkillTrainUiRequest_INFERRED` | `0x00897170` |
| + several `FUN_00809*` / `FUN_008a0*` UI paths | — |

Used after level-up / skill-train / mission chrome / char-sheet build — **client UI rebind**, not C2S.

---

## 3. Artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008a05a0_FUN_008a05a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008a05a0_FUN_008a05a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_008a05a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_008a05a0_FUN_008a05a0.md` |
| Live | decompile ≡ raw (16 insn, 4 BB, CC 2) |

Decompiler warning: jumptable recovery failed at `0x008a05cb` — treated as single vcall (acceptable for this dual).

---

## 4. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| Gated refresh when `+0x684` set | **High** | CF |
| Dual helper calls then optional vcall | **High** | callees sealed |
| Host layout offsets `+0x684` / `+0x664` | **High CF / Tentative English** | — |
| Product method name for vtbl+0x480 | **Tentative** | — |
| `this` class identity | **Tentative** | large UI host shared across dialogs |
| Runtime | **Open** | — |

---

## 5. Gaps

1. Names/roles of `FUN_008af180` / `FUN_008a0370`.
2. Exact vtbl+0x480 method.
3. Whether CharSheet CreateChildWidgets always has `+0x684` populated before call.
