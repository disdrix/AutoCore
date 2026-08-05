# Review B (skeptical / adversarial): `aa_00572730` InventoryGrid_SortAndRepack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572730` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-S OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + ABI + sort/repack role; **reject** overclaims of bit-exact list ownership or product name |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function only sorts without touching placement | **Falsified** — calls FindFree + Place |
| 2 | Places into original grid first | **Overstated** — temp grid allocated; place ECX residual but failure destroys **temp** |
| 3 | Always succeeds | **Falsified** — fail flag + return 0 path |
| 4 | No comparator / fixed order | **Falsified** — `param_2` callback; 2 wrappers pass different fns |
| 5 | Type-4 uses FindFree | **Falsified** — zeros X/Y and skips FindFree |
| 6 | Page-restricted sort | **Falsified** — FindFree page arg `0xffffffff` |
| 7 | `this == NULL` check | **Falsified** — check is `this == 0xFFFFFFD4` (adjusted-null) |
| 8 | `FUN_00572360(this, 0)` is literal null source | **Attack stands as residual** — callee returns 0 if source null; decomp likely dropped real list ptr |
| 9 | DriveControlTick / non-inventory role | **Falsified** — only inventory wrappers call this |
| 10 | Ready for bit-exact seal | **Fail** — runtime/diff open; ECX residuals |

---

## 2. Decisive evidence

### ABI bytes (`read_memory` @ `0x00572730`)

- SEH `LAB_009a4f7f`, `sub esp,0x68`, save EBX/ESI/EDI.
- `mov edi,ecx` / `lea esi,[edi+0x2c]` / `cmp esi,ebx` / early `xor al,al` / **`ret 8`**.
- Success path ends with `mov al,1` pattern near epilogue (`read_memory` @ `0x00572a80` region shows `b0 01` + FS restore).

### Call graph

- **Only** xrefs: `FUN_00572ed0`, `FUN_00572ef0` — both one-line wrappers into this with different compare pointers.
- Callee set includes sealed inventory units only (FindFree/Place/Alloc/ctor) — inventory system, not combat/drive.

### Comparator policy (wrapper decomp, not owned)

`FUN_00572f30(dir, a, b)`: compare `clonebase+0x38` types; if equal, nested object size via vfunc `+0x1e0`→`+0x60`, else short at blob `+0x3f4`; `dir` flips less-than. Proves **external sort key**, not hard-coded in `00572730`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sort+repack role | **High** | Wrong port architecture |
| Temp grid existence | **High** | Missing temp → corrupt this mid-sort |
| Return 0/1 + ret 8 | **High** | Caller error handling |
| Type-4 (0,0) | **High** | Wrong special-case items |
| FindFree page -1 | **High** | Page-clipped free search |
| Place ECX = temp | **Probable** | If place is on this, fail path still odd |
| Commit via 00572360 args | **Tentative** | Empty commit / lost items |
| Fail restore completeness | **Open** | Wipe inventory on failed sort |
| Product name | **Tentative** | Naming only |

---

## 4. What would falsify accept-with-gaps

1. Live show place stamps **this** cells before temp exists — would demote temp-grid claim.
2. Second stack arg not a function pointer — would break comparator model (wrappers contradict).
3. Additional callers outside inventory wrappers with different ABI.

None observed in Ghidra xrefs / live decompile.

---

## 5. Verdict

**accept-with-gaps.** Architecture and ABI sealed; do **not** claim bit-exact intermediate list ownership or product symbol. Residual owner follow-ups: `FUN_00572360` arg recovery, `FUN_00571e10` fail path, wrapper duals.
