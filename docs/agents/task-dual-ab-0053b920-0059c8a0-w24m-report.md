# OWN-ONLY dual agent report — W24-M

| Field | Value |
|---|---|
| Agent | W24-M |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0053b920`, `0x0059c8a0` |
| Tools | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0053b920` CNDHash_Dtor_009cfa7c | **accept-with-gaps** — owning FreeBuckets + machine-sealed freelist `this+0x20`; product name open |
| `aa_0059c8a0` FreelistSlabVector_dtor | **accept** — `_aligned_free` loop + `operator_delete` returns + always-zero three fields sealed |

---

## VA `0x0053b920` — CNDHash_Dtor_009cfa7c

| Field | Value |
|---|---|
| Ghidra | `FUN_0053b920` |
| Canonical | `CNDHash_Dtor_009cfa7c` (**Inferred**) |
| Body | `0x0053b920`–`0x0053b98a` (107 B / `0x6B`, bare `ret`) |
| Role | Owning CNDHash dtor: SEH, vtbl `009cfa7c`, lock log non-fatal, FreeBuckets `005390d0` (reclaim `00538190` deletes values), freelist slabs @ `this+0x20` |
| Caller | Scalar dtor `FUN_0053b900` (vtbl[0]) |
| Callees | `FUN_005390d0`, `FUN_0059c8a0` (`lea ecx,[esi+0x20]`), `FUN_007a4480` ×2 |
| Live ≡ raw surface | Yes; machine seals freelist ECX residual |
| **Verdict** | **accept-with-gaps** |

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053b920_CNDHash_Dtor_009cfa7c.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0053b920_CNDHash_Dtor_009cfa7c.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0053b920_FUN_0053b920.md`
- `docs/reconstruction/raw/aa_0053b920_FUN_0053b920.annotated.md`
- `docs/reconstruction/reconstructed-exact/CNDHash_Dtor_009cfa7c.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0053b920.cpp`
- `docs/reconstruction/functions/aa_0053b920_CNDHash_Dtor_009cfa7c.md`
- `docs/reconstruction/functions/aa_0053b920_FUN_0053b920.md`
- `docs/reconstruction/reviews/A_aa_0053b920_CNDHash_Dtor_009cfa7c.md`
- `docs/reconstruction/reviews/B_aa_0053b920_CNDHash_Dtor_009cfa7c.md`
- Scratch: `docs/reconstruction/tmp/a_0053b920.md`

---

## VA `0x0059c8a0` — FreelistSlabVector_dtor

| Field | Value |
|---|---|
| Ghidra | `FUN_0059c8a0` |
| Canonical | `FreelistSlabVector_dtor` (**Inferred**) |
| Body | `0x0059c8a0`–`0x0059c8e1` (66 B / `0x42`, bare `ret`) |
| Role | Freelist slab vector teardown: `_aligned_free` each slab in `[begin,end)`, optional `operator_delete(begin)`, always null begin/end/cap |
| Callers | 38+ CNDHash dtors; thunk `0x0059cbc0`; from `0053b920` via `lea ecx,[this+0x20]` |
| Callees | `_aligned_free` (IAT `0x009c6578`), `operator_delete` |
| Live vs raw | Surface yes; **machine corrects** decompiler noreturn + zeroing placement |
| **Verdict** | **accept** |

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0059c8a0_FreelistSlabVector_dtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0059c8a0_FreelistSlabVector_dtor.md` | **accept** |

### Artifacts

- `docs/reconstruction/raw/aa_0059c8a0_FUN_0059c8a0.md`
- `docs/reconstruction/raw/aa_0059c8a0_FUN_0059c8a0.annotated.md`
- `docs/reconstruction/reconstructed-exact/FreelistSlabVector_dtor.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0059c8a0.cpp`
- `docs/reconstruction/functions/aa_0059c8a0_FreelistSlabVector_dtor.md`
- `docs/reconstruction/functions/aa_0059c8a0_FUN_0059c8a0.md`
- `docs/reconstruction/reviews/A_aa_0059c8a0_FreelistSlabVector_dtor.md`
- `docs/reconstruction/reviews/B_aa_0059c8a0_FreelistSlabVector_dtor.md`
- Scratch: `docs/reconstruction/tmp/a_0059c8a0.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Owned VAs only; did not re-seal FreeBuckets `005390d0` / reclaim `00538190` / scalar `0053b900` / thunk `0059cbc0` (referenced only).
- Named clean plates preferred; FUN_*.cpp aliases updated to match sealed CF.
- Key residual sealed for dtor family: freelist call is **`lea ecx,[this+0x20]`**, not bare hash this.
