# Review A (reconstruction fidelity): `aa_00560a30` PhysSim_MergeHosts_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560a30` |
| **VA** | `0x00560a30` |
| **Body** | `0x00560a30`–`0x00560c8b` |
| **Canonical name** | `PhysSim_MergeHosts_Inferred` (Ghidra `FUN_00560a30`; **Inferred**) |
| **Prior / alias** | Scaffold `Named_CalleeOf_…_CVOGSpawnPoint_Set_00560a30` (**misleading**) |
| **Review date** | `2026-07-29` (W20-B OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00560a30_PhysSim_MergeHosts_Inferred.md` |
| **System** | physics / island host glue |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_function_callees`, `get_xrefs_to` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Merge two physics hosts/islands** owned by a world/sim object:

1. If `dest == src` → return `dest` (no work).
2. Ensure both activated (`host+0x29 == 0` → `PhysSim_ActivateHost`).
3. Merge list at `host+0x68` (`FUN_00560750`).
4. Append three pointer vectors and one 8-byte vector from `src` onto `dest` (grow via `FUN_005b3300`; capacity high-bit mask `0x7fffffff`).
5. Rebind moved items' host back-pointers (and body table index for vector A).
6. Max/add host scalars.
7. **Swap-remove** `src` from world host table (`world+0x08` data, `world+0x0c` count) using `src+0x24` index; fix moved host's index.
8. Set `dest+0x28` dirty flag from OR of both; **scalar-delete** `src` via `(*vtbl)(1)`.
9. Return `dest`.

Sole static caller: **`PhysSim_FlushPendingBodyPairs_Inferred`** (`0x00561320`) when pending body-pair hosts differ.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00560a30_FUN_00560a30.md` (+ 2026-07-29 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_00560a30_FUN_00560a30.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PhysSim_MergeHosts_Inferred.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_00560a30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00560a30_PhysSim_MergeHosts_Inferred.md` |
| Live decompile | Ghidra @ `0x00560a30` ≡ raw CF |
| Bytes | prologue ECX save; epilogue dual `C2 08 00`; destroy `6a 01 / ff 10` |
| Parent dual | `A/B_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred` |
| Activate dual | `A/B_aa_0055eb80_PhysSim_ActivateHost` |
| Callers | sole `FUN_00561320` @ `0x0056134b` |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=**world**; **`RET 0x8`** | **Confirmed** | prologue + epilogue; parent `mov ecx,esi` |
| Args dest/src hosts; return dest | **Confirmed** | decomp + parent push order hostA/hostB |
| Equal-host early return | **Confirmed** | `cmp` / `je` |
| Activate when `+0x29==0` | **Confirmed** | decomp + ActivateHost dual |
| Vector append + grow pattern | **Confirmed** | four grow sites; elem 4×3 + 8×1 |
| Body list rebind `item+0x44` / index `+0x58` | **Confirmed** | matches flush body host field |
| World table swap-remove via `src+0x24` | **Confirmed** | decomp stores |
| Dirty OR at `+0x28`; destroy src `vtbl(1)` | **Confirmed** | epilogue bytes |
| Sole static caller flush | **Confirmed** | xrefs |
| Product name “island” vs “host” | **Open** | structural host sealed; English open |
| `+0x68` list product type | **Open** | merge helper not dual-owned |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Equal early out | Yes |
| Dual activate gates | Yes |
| +0x68 merge call | Yes |
| Three ptr vectors + 8-byte vector | Yes |
| Scalar max/add | Yes |
| World host table remove | Yes |
| Dirty flag + destroy | Yes |
| `RET 0x8` both paths | Yes |

### Recovered CF (summary)

```c
// Host* __thiscall PhysSim_MergeHosts(World *world, Host *dest, Host *src)
// RET 0x8
if (dest == src) return dest;
if (!dest->act) ActivateHost(dest);
if (!src->act)  ActivateHost(src);
MergeList(dest+0x68, src+0x68);
AppendVectorsAndRebind(dest, src);
MaxAddScalars(dest, src);
SwapRemoveFromWorldHostTable(world, src);
dest->dirty = (dest->dirty || src->dirty);
src->dtor(1);
return dest;
```

---

## 5. Callers / callees

| Direction | Target | Notes |
|---|---|---|
| **Caller** | `0x00561320` PhysSim_FlushPendingBodyPairs_Inferred | sole static |
| **Callee** | `0x0055eb80` PhysSim_ActivateHost | dual-sealed |
| **Callee** | `0x00560750` | merge +0x68 list |
| **Callee** | `0x005b3300` | vector grow |

Parent flush seals: pair vector `world+0x20`, count `+0x24`, body host `body+0x44`, call only when hosts unequal.

---

## 6. Gaps / open

1. Product / PDB English for host/island type and method.
2. Dual of `FUN_00560750` (+0x68 list semantics).
3. English labels for vectors B/C/D (actions / constraints / contacts Tentative).
4. Whether merge order dest=hostA/src=hostB is always preferred by producer (parent pushes A then B).
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — ABI, activate, vector splice, world table remove, destroy, sole flush caller **sealed High/Confirmed**; product English + nested list dual remain.
