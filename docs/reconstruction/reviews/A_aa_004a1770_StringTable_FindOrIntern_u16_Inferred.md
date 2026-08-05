# Review A (reconstruction fidelity): `aa_004a1770` StringTable_FindOrIntern_u16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a1770` |
| **VA** | `0x004a1770`–`0x004a18a8` exclusive (**312 B**) |
| **Canonical name** | `StringTable_FindOrIntern_u16_Inferred` |
| **Ghidra name** | `FUN_004a1770` |
| **Review date** | `2026-07-29` (W34-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-I) |
| **Counterpart** | `reviews/B_aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md` |
| **System** | global string intern table |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (entry/exit + `"Empty"` + table addrs) + xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Find-or-intern C-string into process-global `vector<basic_string>`:

1. SEH `LAB_009a1047`; `SUB ESP,0x3c`.
2. Linear scan `[DAT_00b0360c, DAT_00b03610)` stride **0x1c** with IAT `compare`.
3. **Hit:** return `index & 0xffff`.
4. **Miss empty:** push `"Empty"` (`0x00a41278`) then name via `StringVec_PushBack` on ECX=`0x00b03608`; return `size-1`.
5. **Miss non-empty:** push name only; return `size-1`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a1770_FUN_004a1770.md` (+ W34-I append) |
| Annotated | `docs/reconstruction/raw/aa_004a1770_FUN_004a1770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringTable_FindOrIntern_u16_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a1770.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a1770_FUN_004a1770.md` |
| Named record | `docs/reconstruction/functions/aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md` |
| Live | decompile ≡ CF; body 312 B; xrefs `0x004a1bb1`, `0x004a1c4a` |
| Literal | `read_memory 0x00a41278` → `"Empty"` |
| Table | push uses `MOV ECX,0x00b03608` |

---

## 3. Signature (sealed)

```c
// cdecl 1 formal; bare RET; EAX = u16 index or size-1
unsigned StringTable_FindOrIntern_u16_Inferred(const char* name);
```

| Slot | Source | Conf |
|---|---|---|
| name | Stack param_1 | **High** |
| return hit | `index & 0xffff` | **High** |
| return miss | `size - 1` | **High** |
| cleanup | bare `RET` after `ADD ESP,0x48` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Linear compare scan | **Yes** | **High** |
| Hit → u16 index | **Yes** | **High** |
| Empty seed `"Empty"` + push name | **Yes** | **High** |
| Non-empty miss → push name | **Yes** | **High** |
| Product table English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product name of global table / owning subsystem.
2. Why index 0 is forced to `"Empty"` (sentinel convention).
3. Table init / teardown sites (unowned).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
