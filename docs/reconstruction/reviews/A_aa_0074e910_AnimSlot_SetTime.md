# Review A (reconstruction fidelity): `aa_0074e910` AnimSlot_SetTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e910` |
| **VA** | `0x0074e910` |
| **Body** | `0x0074e910`–`0x0074e9c2` (**179** B; exclusive end `0x0074e9c3`) |
| **Canonical name** | `AnimSlot_SetTime` |
| **Prior / alias** | `FUN_0074e910` |
| **Review date** | `2026-07-29` (W21-J OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0074e910_AnimSlot_SetTime.md` |
| **System** | client visual / animation slot |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs/callers (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Anim-slot time apply:** store playhead + end/duration ref, clamp or wrap time by mode byte, recompute derived remaining, clear two cache-ish dwords, mirror final time.

Roles (caller evidence):

1. Load path `Object_LoadOrReplaceAnimSlot` — `SetTime(slot, 0, duration)` then write `+0x4c`.
2. Blend select / visual tick paths sample time then call this (16 xrefs).
3. Operates on `0x78`-byte slot object from ctor `FUN_0074ed90`.

Structural name **`AnimSlot_SetTime`**. Product/PDB spelling open.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0074e910_FUN_0074e910.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e910_FUN_0074e910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimSlot_SetTime.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0074e910.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074e910_AnimSlot_SetTime.md` |
| Live decompile | clamp / fmod / shared tail CF |
| Live bytes | full 179 B body; epilogue `c2 08 00` |
| Sibling ctor | `FUN_0074ed90` defaults `+0x4c=1`, rate `1.0` |

---

## 3. Byte / ABI seal (`read_memory` + decompile)

```
entry:   movss xmm0,[esp+4]; push esi; mov esi,ecx; cmp byte [esi+0x4c],0 ...
stores:  [esi+0x44]=time; [esi+0x40]=param_3
wrap:    fld …; fld [esi+0x48]; call _CIfmod; compare g_flZero @ 0x00a0f518
tail:    [esi+0x34]=param_3 - time/rate; [esi+0x50]=0; [esi+0x68]=0; [esi+0x6c]=time
epilogue: pop edi; pop esi; ret 8
```

| Claim | Evidence | Conf |
|---|---|---|
| Body 179 B through last `eb aa` | `get_function_by_address` + full hex | **High** |
| `__thiscall` ECX=slot | prologue `mov esi,ecx`; callers load slot into ECX | **High** |
| Two float stack args + `ret 8` | `c2 08 00` + decompile params | **High** |
| Mode `+0x4c`: 0=clamp, else fmod | decompile + `cmp byte [esi+0x4c],0` | **High** |
| Clamp `[0, +0x48]` | clamp path min/max CF | **High** |
| Wrap + negative repair | fmod then `if < 0 add length` | **High** |
| `+0x34 = param_3 - time/rate` | shared tail SSE math | **High** |
| Zero `+0x50`/`+0x68`; copy `+0x6c` | `c7 46 50…` / `c7 46 68…` / `89 56 6c` | **High** |
| Only callee `_CIfmod` on wrap | analyze callees | **High** |
| Decompile ≡ clean CF | side-by-side | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Store time + end ref | **Yes** |
| Clamp branch | **Yes** |
| Fmod + negative fix | **Yes** |
| Derived + clears + mirror | **Yes** |
| No invented domain (physics/mission) | **Yes** |
| `ret 8` preserved | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Anim slot time worker | **High** | load/select duals + ctor size |
| Field offsets sealed | **High** | |
| Product spelling | **Low–Med** | residual |
| `param_3` English (end vs duration) | **Med** | algebra sealed; name structural |
| `+0x50`/`+0x68` semantic role | **Med** | values sealed as zero |
| Runtime / bit-exact | Open | |

---

## 6. Gaps

1. Product/PDB symbol spelling.
2. Exact product English for `param_3` / remaining field `+0x34`.
3. Why load path sets mode flag **after** SetTime (ctor default wrap first).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept** — clamp/wrap time worker sealed; product spelling residual only.
