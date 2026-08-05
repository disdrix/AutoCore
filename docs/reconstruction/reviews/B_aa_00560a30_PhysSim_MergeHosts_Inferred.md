# Review B (skeptical / adversarial): `aa_00560a30` PhysSim_MergeHosts_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560a30` |
| **VA** | `0x00560a30` |
| **Canonical name** | `PhysSim_MergeHosts_Inferred` |
| **Review date** | `2026-07-29` (W20-B OWN-ONLY dual) |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00560a30_PhysSim_MergeHosts_Inferred.md` |
| **System** | physics / island host glue |
| **Verdict** | **accept-with-gaps** on shape; **reject** spawn/pair-enqueue/step roles |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “CVOGSpawnPoint set-active leaf” | **Falsified** — scaffold name chain only; sole static caller is body-pair flush |
| “Pair enqueue / PushBodyPair” | **Falsified** — that is `0x0055efd0`; this **consumes** merge after host mismatch |
| “Island step integrator” | **Falsified** — step is `0x00561910`; it *calls* flush which *calls* this |
| Free-standing 2-arg `Merge(hostA, hostB)` | **Falsified** — parent dual + prologue seal **ECX=world** |
| “Compare integer island IDs” | **Falsified** (parent B already) — args are **host object pointers** |
| “Soft pose / vehicle net” | **Falsified** — pure host list splice + table remove |
| Product name proven “Island::merge” | **Unproven** — structural host merge; English open |
| `RET` bare / 0 stack | **Falsified** — **`C2 08 00`** (two host* args) |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `FUN_00560a30(param_2, param_3)` without this | **ECX = world** required; decomp drops it |
| `param_3 + 0x1a` looks like weird offset | **dword index 0x1a → byte +0x68** |
| `param_2 + 10` as pointer arithmetic | **dword 10 → byte +0x28** dirty flag |
| `undefined4 *` everywhere | Clean uses `uint32_t` / `Host*` / `World*` |
| Scaffold self-callee `FUN_00560a30` in readability | **False** — callees are activate / merge-list / grow only |
| First activate call without explicit `mov ecx,world` in first 64 B | Entry ECX still world until overwritten; second path reloads `mov ecx,ebx` — ActivateHost dual owns full ABI |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Is vector A really bodies? | Items get `+0x44 = host` and `+0x58 = index`; flush reads **body+0x44** as host | **High** for body list |
| Are B/C “wheels”? | Only host backlink offsets sealed (`+0x10`, `+0x14`); type English **Open** | **Tentative** |
| Does destroy free without delete? | `push 1; call [vtbl]` is MSVC scalar-deleting dtor pattern | **High** delete |
| World table could be pair table? | Uses `src+0x24` index and writes moved host's `+0x24` — host registry, not 8-byte pairs (`world+0x20`) | **High** |
| Merge loses src-only activation? | Both activated before splice; dest dirty OR'd | **High** |

---

## 4. Surviving contract (minimal)

```
// thiscall on World/sim
// Merges src host into dest host; destroys src; returns dest

Host* PhysSim_MergeHosts_Inferred(
    World* world, // ECX
    Host* dest,   // survivor
    Host* src);   // absorbed
// RET 0x8
//
// No-op if dest == src.
// Ensures ActivateHost on either with +0x29 == 0.
// Appends host-owned vectors; rebinds body host pointers (+0x44).
// Removes src from world host table (data +0x08, count +0x0c).
// (*src->vtbl)(src, 1) then return dest.
//
// Called only from FlushPendingBodyPairs when body hosts differ.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| ECX=world, RET 0x8, dest/src | **Agree** |
| Activate gates +0x29 | **Agree** |
| Four vector appends + grow | **Agree** |
| Body rebind +0x44 / +0x58 | **Agree** |
| World host swap-remove | **Agree** |
| Destroy src via vtbl(1) | **Agree** |
| Sole caller flush | **Agree** |
| Product “island” English | **Agree open** |
| +0x68 list type | **Agree open** — do not invent “contact manifold” as proven |

---

## 6. Residual risk

1. `FUN_00560750` not dual-owned — merge-list side effects beyond append unknown.
2. Order dest=A/src=B assumed from parent push; reverse merge not observed.
3. No runtime proof under island step load.
4. Vector B/C/D English labels Tentative.

**Verdict:** **accept-with-gaps** — reject spawn/net/step misroles; accept host merge ABI + list splice + table remove + destroy sealed by decompile, parent flush dual, and epilogue bytes.
