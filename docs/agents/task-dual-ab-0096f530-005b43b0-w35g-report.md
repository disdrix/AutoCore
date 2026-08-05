# Dual A/B report — W35-G OWN `aa_0096f530` + `aa_005b43b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-G  
**Scope:** VAs `0x0096f530`, `0x005b43b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-G).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0096f530` RefCountedPtr3Flags_DefaultCtor_Inferred | **accept-with-gaps** — leaf default ctor zeros pointer + 3 flag bytes (16 B); return-this sealed; flag English residual |
| `aa_005b43b0` StdList_AllocSentinel_0x30_Inferred | **accept-with-gaps** — `new(0x30)` circular next/prev factory (26 B); EAX return sealed; payload English residual |

---

## VA `0x0096f530` — sealed facts

1. **Body:** `0x0096f530`–`0x0096f53f` inclusive (**16 B** / `0x10`); next fn SEH @ `0x0096f540`.
2. **ABI:** **ECX=`this`** (`mov eax,ecx`); bare **`RET`** (`C3`); returns **this** in EAX. **No SEH**. Leaf.
3. **Semantics:** Default-construct **8-byte** handle shell:
   - dword **`*this = 0`**
   - bytes **`this+4/+5/+6 = 0`**
   - byte **`this+7` not written** (padding under stride-8 hosts)
4. **Classification:** leaf / worker (default ctor).
5. **Callers:** 28 xrefs / 16 named — `CVOGTacArc_ctor`, `FUN_004c0640` (ParticleFluidPhase ×2 @ +0x84/+0x8c), `FUN_00581e20`, graphics/UI; vector-ctor element size **8** with peer dtor `FUN_0096f510`.
6. **Callees:** none.
7. **Name:** `RefCountedPtr3Flags_DefaultCtor_Inferred` (Ghidra `FUN_0096f530`; **Inferred**). Sibling pointer-only: `RefCountedPtr_DefaultCtor_Inferred` @ `0x0096ef70`. Peer dtor (context): `FUN_0096f510`.
8. **Hex:** `8b c1 33 c9 89 08 88 48 04 88 48 05 88 48 06 c3`. Decompile ≡ raw CF; decomp void understates return.

### Gaps

- Product English for payload type + three flag meanings.  
- Full dual of peer dtor `0096f510`.  
- Whether +7 is always pad vs latent 4th flag.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096f530_RefCountedPtr3Flags_DefaultCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096f530_RefCountedPtr3Flags_DefaultCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096f530_FUN_0096f530.md` |
| Annotated | `docs/reconstruction/raw/aa_0096f530_FUN_0096f530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RefCountedPtr3Flags_DefaultCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f530.cpp` |
| Function | `docs/reconstruction/functions/aa_0096f530_FUN_0096f530.md` |
| Function named | `docs/reconstruction/functions/aa_0096f530_RefCountedPtr3Flags_DefaultCtor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0096f530.md` |

---

## VA `0x005b43b0` — sealed facts

1. **Body:** `0x005b43b0`–`0x005b43c9` inclusive (**26 B** / `0x1A`; pad `CC`).
2. **ABI:** no formals; bare **`C3`**; **EAX = node*** (decomp void wrong; wrapper_hint + callers assign).
3. **Semantics:** MSVC-style **list sentinel factory**:
   - **`operator_new(0x30)`**
   - if non-null: **`*node = node`** (next = self)
   - if `node+4 != 0`: **`*(node+4) = node`** (prev = self)
   - payload **+0x08..+0x2F** untouched
4. **Classification:** wrapper/factory (complete body; not a thunk).
5. **Callers:** 5 — `FUN_004438c0` NestedHashBag_Ctor_Sentinel0x30; `FUN_00463bd0` NestedHash_Ctor_Sentinel0x30; `FUN_005b3f60` / `FUN_005b4260` list@+0x10; `FUN_004d8a10` large host head+size0.
6. **Callees:** `operator_new`.
7. **Name:** `StdList_AllocSentinel_0x30_Inferred` (Ghidra `FUN_005b43b0`; **Inferred**). Family: 0xC @ `0x004933f0`, 0x18 @ `0x00457c60`, SEH 0xC @ `0x0040fb90`; Ass NestedHash uses 0x28 @ `0x00423d60` (not this).
8. **Hex skeleton:** `6a 30 e8 .. 83 c4 04 85 c0 74 02 89 00 8d 48 04 85 c9 74 02 89 01 c3`. Identical CF to 0xC/0x18 factories with different push size.

### Gaps

- Product payload meaning of +0x08..+0x2F.  
- Why 0x30 vs Ass 0x28 for similar NestedHash bag shapes.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b43b0_StdList_AllocSentinel_0x30_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b43b0_StdList_AllocSentinel_0x30_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b43b0_FUN_005b43b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b43b0_FUN_005b43b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_AllocSentinel_0x30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b43b0.cpp` |
| Function | `docs/reconstruction/functions/aa_005b43b0_FUN_005b43b0.md` |
| Function named | `docs/reconstruction/functions/aa_005b43b0_StdList_AllocSentinel_0x30_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005b43b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0096f530` | Port as **default ctor** for 8-byte handle: null pointer + three flag bytes. **ECX=this**, return this, bare RET. Do **not** zero +7. Do **not** merge with pointer-only `0096ef70`. Pair release with peer dtor `0096f510` at host sites. |
| `005b43b0` | Port as **0x30 sentinel factory only**: `new(0x30)` → self-link next/prev → return EAX. Do **not** free or init size. Callers zero size separately. Do **not** substitute Ass `CircularSentinel_Alloc0x28` for NestedHash0x30 hosts. |
| Pair with | W25-N `RefCountedPtr_DefaultCtor` (`0096ef70`); W32-P `StdList_AllocSentinel_0xC`; W30-E `_0x18`; W34 NestedHash0x30 ctors (`00463bd0` / `004438c0`); W30-O Obj list@+0x10 (`005b3f60`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint8_t` / explicit structs / `void*`).  
- Closes wave35 partition W35-G high-mention nested callees: handle default ctor used widely by graphics/UI/ParticleFluidPhase, and 0x30 list sentinel used by NestedHash0x30 + Obj list shells.
