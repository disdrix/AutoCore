# OWN-ONLY dual agent report — W24-P

| Field | Value |
|---|---|
| Agent | W24-P |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0062a410`, `0x00628f10` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0062a410` `ActionManager_NotifyListenersAndCompact_Inferred` | **accept-with-gaps** — 52 B cdecl 2-arg; reverse notify vtbl+0xC; EAX tail compact residual sealed; product English open |
| `aa_00628f10` `ActionHost_RemoveReverseListEntry_Inferred` | **accept-with-gaps** — 84 B thiscall ret 4; find+shift remove; clear action+0x10; dirty host+0x28; product English open |

---

## VA `0x0062a410` — ActionManager_NotifyListenersAndCompact_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_0062a410` |
| Canonical | `ActionManager_NotifyListenersAndCompact_Inferred` (**Inferred** — no plate string) |
| Body | `0x0062a410`–`0x0062a444` exclusive (**52** / `0x34` B) |
| Role | Reverse-walk manager listener table `+0x3c/+0x40`; each non-null `vtbl+0xC(action)`; tail compact via `FUN_005fff20` |
| ABI | **cdecl** stack `manager*`, `action*`; parent `ADD ESP, 8`; epilog **JMP** `005fff20` with **EAX=manager+0x3c** |
| Callers | `FUN_0055df40` only |
| Callees | `FUN_005fff20` |
| Live ≡ raw | Yes (+ decomp residual: compact uses **EAX**, not empty arg list) |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **Bytes:** full 52 B body via `read_memory`; no `ret N` — tail JMP.
2. **Table:** base `*(manager+0x3c)`, count `*(manager+0x40)`.
3. **Notify:** reverse index; skip null; `thiscall` listener + stack action @ vtbl+0xC.
4. **Compact:** `FUN_005fff20` `in_EAX = manager+0x3c` (PtrVec header).

### Gaps

1. Product English for manager / listener.
2. Nested dual of `FUN_005fff20` (not owned).
3. Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0062a410_FUN_0062a410.md`
- `docs/reconstruction/raw/aa_0062a410_FUN_0062a410.annotated.md`
- `docs/reconstruction/reconstructed-exact/ActionManager_NotifyListenersAndCompact_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0062a410.cpp`
- `docs/reconstruction/functions/aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md`
- `docs/reconstruction/functions/aa_0062a410_FUN_0062a410.md`
- `docs/reconstruction/reviews/A_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md`

---

## VA `0x00628f10` — ActionHost_RemoveReverseListEntry_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_00628f10` |
| Canonical | `ActionHost_RemoveReverseListEntry_Inferred` (**Inferred** — no plate string) |
| Body | `0x00628f10`–`0x00628f64` exclusive (**84** / `0x54` B); last `ret 4` |
| Role | Linear find + order-preserving shift-remove of action* from host reverse list; clear back-link; dirty host |
| ABI | ECX=`host`, stack `action*`, **`ret 4`**, void |
| Callers | `FUN_0055df40`, `FUN_00560f70`, `FUN_00561580` |
| Callees | none |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **Bytes:** full 84 B body via `read_memory`; `C2 04 00` epilogue.
2. **List:** base `host+0x4c`, count `host+0x50`.
3. **Always** `count--` after search; shift while `index < new_count`.
4. **Side effects:** `action+0x10 = 0`; `host+0x28 = 1`.
5. Parent call site: **`ECX = *(action+0x10)`** (W23-P residual sealed here as this unit's this).

### Gaps

1. Product English for host class.
2. Dirty `+0x28` consumer.
3. Not-found count-- edge.
4. Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_00628f10_FUN_00628f10.md`
- `docs/reconstruction/raw/aa_00628f10_FUN_00628f10.annotated.md`
- `docs/reconstruction/reconstructed-exact/ActionHost_RemoveReverseListEntry_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00628f10.cpp`
- `docs/reconstruction/functions/aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md`
- `docs/reconstruction/functions/aa_00628f10_FUN_00628f10.md`
- `docs/reconstruction/reviews/A_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write dual artifacts for non-owned helpers (`005fff20`, `0055df40`, `00560f70`, `00561580`, `0062a490`, …). Parent `0055df40` already dual-sealed by W23-P.
- Prior 2026-07-23 raw bodies preserved; W24-P live seal sections appended.
- Clean plates prefer named CF; FUN_* scaffolds updated to sealed bodies.
- Names are **Inferred** (no plate strings); structural roles match W23-P parent dual language.

## This report

`docs/agents/task-dual-ab-0062a410-00628f10-w24p-report.md`
