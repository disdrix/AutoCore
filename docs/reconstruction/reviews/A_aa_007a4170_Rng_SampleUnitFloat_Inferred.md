# Review A (reconstruction fidelity): `aa_007a4170` Rng_SampleUnitFloat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4170` |
| **VA** | `0x007a4170`–`0x007a41d4` exclusive (**0x64 B**) |
| **Canonical name** | `Rng_SampleUnitFloat_Inferred` |
| **Ghidra name** | `FUN_007a4170` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_007a4170_Rng_SampleUnitFloat_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | WQ9D-F OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/scale/host layout sealed; product English open |

---

## 1. Purpose

Leaf **unit float** draw from the global RNG ushort table on host `DAT_00d20c1c` (via getter). Sequential (`index < 0`) advances cursor; indexed (`index >= 0`) is pure lookup with power-of-two reduce.

```c
// __thiscall RET 4; float ST0
float Rng_SampleUnitFloat_Inferred(RngHost* this, uint32_t index);
```

Not a window copy (`0x0051b720`). Not a heap clone (`0x0058ab60`). Not the singleton getter (`0x007a4330`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007a4170_FUN_007a4170.md` |
| Annotated | `docs/reconstruction/raw/aa_007a4170_FUN_007a4170.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Rng_SampleUnitFloat_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_007a4170.cpp` |
| Twin named scaffold | `Named_CalleeOf_CVOGReaction_Dispatch_007a4170.cpp` (legacy name — superseded) |
| Live Ghidra | `decompile_function` + `read_memory` body + `DAT_00aaa638` |
| Sibling dual | `A\|B_aa_0051b720_Rng_CopyUnitTableWindow_Inferred` |
| Getter | `CVOGReaction_RandomUnitScalar` @ `0x007a4330` → `&DAT_00d20c1c` |
| Caller | `FUN_00508a00` @ `0x00508a31` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x007a4170`–`0x007a41d4` excl. | **Confirmed** | `get_function_by_address` + `CC` pad |
| `__thiscall` + `RET 4` | **Confirmed** | dual `C2 04 00` |
| Sequential when `(int)index < 0` | **Confirmed** | `test eax; jge indexed` |
| Wrap `cursor > 0xFFFFF` → 0 | **Confirmed** | `cmp [ecx+0xC],0x100000` / `jl` / store 0 |
| Table `*(ushort*)(base+cursor*2)` | **Confirmed** | `66 8B 04 50` |
| Cursor `+= 1` sequential only | **Confirmed** | indexed path does not write `+0xC` |
| Scale `DAT_00aaa638` | **Confirmed** | `fmul [0x00aaa638]`; bytes `80 00 80 37` ≈ 1/65535 |
| Indexed mask `0x800FFFFF` + wrap | **Confirmed** | `and` / `jns` / `dec;or;inc` |
| Leaf (no callees) | **Confirmed** | analyze callees empty |
| Callers ≥ 2 | **Confirmed** | `0x00508a31`, `0x0057ed44` |
| Product C++ name | **Inferred** | no string/RTTI |

---

## 4. Control flow vs siblings

| Stage | This unit | CopyWindow `0051b720` | CloneSeeded `0058ab60` |
|---|---|---|---|
| Alloc | none | none | `new[] 0x4B0` |
| Force seed | no | no | yes |
| Advance | **+1 if sequential** | **+1 always** | **+1** |
| Return | **float ST0** | old cursor EAX | heap ptr |
| Scale | `* DAT_00aaa638` | raw ushorts | raw ushorts |

---

## 5. Gaps (acceptable)

1. Product / PDB name.
2. Full enumeration of live index values (which callers pass sequential `-1` vs explicit index).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| ABI / epilogue sealed | **Pass** |
| Scale constant sealed | **Pass** |
| Sibling differentiation | **Pass** |
| Clean meaningful names | **Pass** |
| Verdict | **accept-with-gaps** |
