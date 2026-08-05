# Review A (reconstruction fidelity): `aa_004bae70` CVOGReaction_ResolveObjectTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae70` |
| **VA** | `0x004bae70`–`0x004baeb4` (body; `ret 0x0c`) |
| **Canonical name** | `CVOGReaction_ResolveObjectTarget` |
| **Review date** | `2026-07-29` (dual residual **strengthen**; first dual 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| **System** | object-resolve / reaction (client world) |
| **Evidence pass** | Live Ghidra `decompile_function` + **`read_memory` body** (2026-07-29); callers `get_function_callers` / `get_xrefs_to`; callees `0x004e3260` / `0x004e23d0` decompile + `read_memory` |
| **Verdict** | **accept-with-gaps** (CF + dual-table switch **High**/sealed; flag English + product table names open) |

---

## 1. Purpose

Tiny **permissioned dual-table lookup** used across reactions, skills, net recv, and patrol:

1. Invalid TFID halves → 0.
2. `bGlobal==0` → require `ctx+0xd`, lookup on hash table `*(ctx+0x8)`.
3. `bGlobal!=0` → require `ctx+0xc`, lookup on hash table `*(ctx+0x4)`.
4. Lookup is `FUN_004e3260` (**thiscall** on selected table) → object* at hash-node `+0xc`, or 0.

**No mutation.** Does not spawn/remove; does not walk beyond the hash helper.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| Annotated | `docs/reconstruction/raw/aa_004bae70_CVOGReaction_ResolveObjectTarget.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_ResolveObjectTarget.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| Counterpart B | `reviews/B_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| Thin TFID wrap | `Object_ResolveFromTFID` `0x004bb950` (plate: `bGlobal,dwCoidLo,dwCoidHi`) |
| Scratch | `tmp/a_004bae70.md` |

---

## 3. Signature (sealed)

```c
// __thiscall  ECX = resolve context (reaction/world manager)
// stack args cleaned by ret 0x0c  (3 dwords)
void * CVOGReaction_ResolveObjectTarget(
    void *ctx,              // this ECX — flags +0xc/+0xd; table ptrs +0x4/+0x8
    unsigned char bGlobal,  // TFID global / domain select (0 vs non-0)
    unsigned int coidLo,    // idA — matched at hash-node +0x18
    unsigned int coidHi);   // idB — matched at hash-node +0x1c
// returns object* or NULL
```

Callers typically show **three** stack args only; ECX is the shared resolve context (same object that owns large reaction offsets in `RemoveObject`, etc.).

---

## 4. Control flow (assembly-sealed; decompiler incomplete)

Ghidra decompile matches branch **shape** but **drops** the `mov ecx,[ecx+4|8]` table select before `FUN_004e3260`. Prefer image:

```
// 0x004bae70 (read_memory 2026-07-29)
eax = coidLo; edx = coidHi;
if ((coidLo & coidHi) == 0xFFFFFFFF) return 0;   // both halves all-ones

if (bGlobal != 0) {
  if (*(char*)(ctx + 0xc) == 0) return 0;
  ecx = *(void**)(ctx + 0x4);          // GLOBAL table
  return FUN_004e3260(ecx, coidLo, coidHi);  // thiscall; ret 8
} else {
  if (*(char*)(ctx + 0xd) == 0) return 0;
  ecx = *(void**)(ctx + 0x8);          // LOCAL / non-global table
  return FUN_004e3260(ecx, coidLo, coidHi);
}
```

| Stage | Match clean≡image | Confidence |
|---|---|---|
| Invalid `(lo & hi) == -1` → 0 | **Yes** (≡ both `== 0xFFFFFFFF`) | **High** |
| `bGlobal==0` → flag `+0xd`, table `+0x8` | **Yes** after strengthen | **High** (bytes) |
| `bGlobal!=0` → flag `+0xc`, table `+0x4` | **Yes** after strengthen | **High** (bytes) |
| Both arms call same `FUN_004e3260` with **different ECX** | **Yes** (was missing in scaffold decompile) | **High** |
| No stores / no other callees | **Yes** | **High** |
| `ret 0x0c` (3 stack args) | **Yes** | **Confirmed** |

### Invalid-id identity

`(a & b) == 0xFFFFFFFF` holds **iff** `a == b == 0xFFFFFFFF` (all bits must be set in both). Sentinel pair `(-1,-1)`.

---

## 5. Callee contract (supporting; owned residual stops at call)

| Addr | Role | Sealed bits |
|---|---|---|
| `FUN_004e3260` `0x004e3260` | Hash lookup **thiscall** | ECX=table; `bucket = coidLo & *(table+0x8)`; head=`*( *(table+0x10) + bucket*4 )`; walk `FUN_004e23d0`; return `*(node+0xc)` or 0; `ret 8` |
| `FUN_004e23d0` `0x004e23d0` | Chain walk | Match `node+0x18/+0x1c` to (lo,hi); next `node+0x10`; out-prev via stack; result left in EAX |

Hash-node layout corroborated by `CVOGReaction_RemoveObject` insert (`puVar7[3]=obj` → `+0xc`; `[6]/lo` → `+0x18`; `[7]/hi` → `+0x1c`).

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists @ `0x004bae70` | **Confirmed** | Ghidra + bytes |
| `__thiscall` + 3 stack args (`ret 0x0c`) | **High** | image epilogue |
| Invalid when both id halves `0xFFFFFFFF` | **High** | `and` + `cmp -1` |
| Dual domain: flag `+0xc`↔table `+0x4`, flag `+0xd`↔table `+0x8` | **High** | **assembly**; decompiler omitted table loads |
| `bGlobal` selects domain (0 → local table path) | **High** CF | name from TFID `bGlobal` / `Object_ResolveFromTFID` plate |
| Lookup always `FUN_004e3260` | **High** | both CALL rel32 → `0x004e3260` |
| Return = object* @ hash-node `+0xc` | **High** | callee bytes + RemoveObject insert |
| No mutation in this body | **High** | no stores |
| Flag English (“enable global table”) | **Tentative** | only known as non-zero gate |
| Product name of tables / `FUN_004e3260` | **Open** | residual FUN_* |
| ctx exact C++ type | **Tentative** | large reaction/world object; not fully typed here |

---

## 7. Representative callers (mode evidence)

| Caller | Mode / first stack arg | Notes |
|---|---|---|
| `CVOGReaction_RemoveObject` `0x004db8b0` | **literal 0** | local-table path; fail path also probes hash via `FUN_004e23d0` |
| `Object_ResolveFromTFID` `0x004bb950` | `pTfid->bGlobal` | pure TFID unwrap |
| `Client_LookupObjectByTfid_Inferred` `0x004bb0a0` | `bGlobal` | then vtbl `+0x1dc` on result |
| `FUN_004baf50` | `*(tfid+2)` byte | then vtbl `+0x1cc` |
| Thin family `0x004baec0`…`0x004bb3a0` | passthrough (mode,lo,hi) | various vtbl unwraps |
| `Skill_ResolveTargetList` / `Skill_ApplyEffectsOnTarget_Inferred` | TFID global byte | combat/skills |
| Many Client_Recv* / patrol / map | TFID fields | high fan-in (~100 xrefs) |

**Why RemoveObject passes leading 0:** that is **`bGlobal=0`** (local domain), not a missing `this`. `this` is ECX.

---

## 8. Gaps

1. Product / PDB names for `FUN_004e3260` / `FUN_004e23d0` and the two table objects at `ctx+4` / `ctx+8`.
2. English meaning of enable-flags `ctx+0xc` / `ctx+0xd` (who sets them; always 1 in live play?).
3. Full C++ type of `ctx` (reaction manager vs world vs sector map) — layout only partially known via sibling `RemoveObject`.
4. Runtime observation of which table hits for a given TFID.
5. Bit-exact / differential vs retail image open.

**Verdict:** **accept-with-gaps**.
