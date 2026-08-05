# Review A (reconstruction fidelity): `aa_004962b0` EquipGfxHost_ClearListIfFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004962b0` |
| **VA** | `0x004962b0` |
| **Body span** | `004962b0` – `004962c5` inclusive (**22** bytes; exclusive end `004962c6`) |
| **Canonical name** | `FUN_004962b0` (Ghidra) |
| **Proposed name** | `EquipGfxHost_ClearListIfFlag_Inferred` (**Probable** role; product string absent) |
| **Prior / alias** | `Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004962b0` (parent-seed only) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B create — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ **bytes**) |
| **Counterpart** | `reviews/B_aa_004962b0_EquipGfxHost_ClearListIfFlag_Inferred.md` |
| **Scratch** | `reviews/a_004962b0.md` |
| **System** | `inventory-transfer` (equip/unequip refresh chain) + client gfx host |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Gated clear of a dword vector** embedded at **`host+0xA8`**, when the **arm flag** at **`host+0x53`** is non-zero.

This is the **real work leaf** behind `Client_MaybeRefreshEquipGfxHost` (`0x0092f120`): callers resolve a gfx/FX host pointer (commonly `*(obj+0xE898)`) into `ECX`, then call this unit. On the armed path it does **not** invent mesh rebuild; it **resize-clears** the vector at `host+0xA8` via `FUN_004367f0(this=host+0xA8, count=0, fill=0)`.

**Calling convention:** MSVC `__fastcall` / `__thiscall` shape — object in **ECX**, **zero stack args**, plain **`ret`** (`c3`).

---

## 2. Machine proof (authoritative — decompiler incomplete)

Live `read_memory` @ `0x004962b0` (22 body bytes; then `cc` pad):

```text
004962b0  80 79 53 00           cmp  byte ptr [ecx+0x53], 0
004962b4  74 0f                 je   004962c5          ; flag clear → ret
004962b6  6a 00                 push 0                 ; stack arg2 (fill / unused on shrink)
004962b8  6a 00                 push 0                 ; stack arg1 (count = 0)
004962ba  81 c1 a8 00 00 00     add  ecx, 0xA8         ; this → host+0xA8 vector
004962c0  e8 2b 05 fa ff        call FUN_004367f0      ; thiscall; callee ret 8
004962c5  c3                    ret
```

Hex: `80795300740f6a006a0081c1a8000000e82b05faffc3`

**Critical correction vs frozen raw decompile:** Ghidra prints `FUN_004367f0(0,0)` with **no** `this` adjustment. Bytes prove **`add ecx, 0xA8`** before the call. Clean / dual CF must follow **bytes**, not the incomplete decompiler text.

Live `force_decompile` 2026-07-29 still shows the incomplete form (same as 2026-07-23 raw) — known decompiler elision; sealed by assembly.

---

## 3. Inspected artifacts

| Artifact | Path / evidence |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004962b0_FUN_004962b0.md` (body frozen; append re-verify) |
| Annotated | `docs/reconstruction/raw/aa_004962b0_FUN_004962b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004962b0.cpp` |
| Named scaffold | `…/Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004962b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004962b0_FUN_004962b0.md` |
| Live decompile | Ghidra `decompile_function` + `force_decompile` @ `0x004962b0` |
| Live bytes | `read_memory` @ `0x004962b0` (32 B) |
| Live xrefs | `get_function_xrefs` / `get_function_callers` / `get_assembly_context` |
| Callee (identity only) | `FUN_004367f0` @ `0x004367f0` — dword-vector resize; `ret 8`; **not** dualed here |
| Parent wrapper | `Client_MaybeRefreshEquipGfxHost` @ `0x0092f120` (tail-`jmp` to this) |

**Not performed:** Launcher, runtime golden, package bit-exact, ledger updates, dual of `FUN_004367f0`, product rename in Ghidra.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 22 B `004962b0`–`004962c5`, plain `ret` | **High** | `read_memory` + function bounds |
| ECX = host; no stack args of **this** unit | **High** | Call sites `mov ecx,eax` / ECX already host; `c3` |
| Gate: `*(u8*)(host+0x53) != 0` else no-op | **High** | `cmp [ecx+0x53],0` / `je` |
| Armed path: `ecx += 0xA8` then call | **High** | Imm32 `0xA8` in `add ecx` — not decompiler fiction |
| Stack args to callee: **two zeros** (count=0, fill=0) | **High** | Two `push 0` + callee `ret 8` |
| Callee `FUN_004367f0` is **dword-vector resize** | **High CF** (callee identity) | `begin@+4`, `end@+8`, size `>>2`; grow `FUN_004507a0` / shrink `FUN_00410490` |
| With **count=0**, non-empty vector is **cleared** | **High CF** | Shrink branch when `0 < size` |
| Empty vector + flag set → **no-op** after call | **High** | Both grow/shrink predicates fail |
| **13** code xrefs (12 named callers + 1 site) | **High** | Live xref dump 2026-07-29 |
| Dominant host source: `*(something+0xE898)` | **High** | Asm context at nearly all sites |
| Parent `0x0092f120` tail-`jmp` with ECX=host | **High** | `jmp` not `call` at `0x0092f136` |
| Equip/unequip chain uses this leaf | **High** | Parent dual + `Client_RecvInventoryEquip` path |
| English product class/method name | **Open / Tentative** | `_Inferred`; no RTTI/string on body |
| Element type of vector at `+0xA8` | **Open** | dword stride sealed; payload English open |
| Meaning of flag `+0x53` (dirty vs enable) | **Probable dirty/arm** | Only polarity sealed: non-zero → clear |

---

## 5. Control flow: clean ≡ bytes (override incomplete decompile)

| Stage | Match |
|---|---|
| Load flag `host+0x53` | **Yes** |
| Zero → return | **Yes** |
| Non-zero → push 0, push 0 | **Yes** |
| `this = host+0xA8` | **Yes** (**bytes**; decompile missing) |
| `FUN_004367f0` thiscall | **Yes** |
| Plain `ret` | **Yes** |
| No inventory/equip/network writes in **this** body | **Yes** |

### 5.1 Sealed pseudocode

```c
// __fastcall / __thiscall — ECX = gfx host; no stack args; ret
void EquipGfxHost_ClearListIfFlag_Inferred(void *host)
{
    if (*(char *)((char *)host + 0x53) == 0)
        return;

    // FUN_004367f0: thiscall vector resize; count=0 clears [begin,end) of dword elems
    // this = host+0xA8  (vector object: +4 begin, +8 end)
    FUN_004367f0((char *)host + 0xA8, /*count*/ 0, /*fill*/ 0);
}
```

### 5.2 Callee contract used here (not a full dual of `0x004367f0`)

| Item | Value |
|------|-------|
| VA | `0x004367f0` |
| ABI | `__thiscall`, **2** stack dwords, **`ret 8`** (`c2 08 00`) |
| `this+4` / `this+8` | begin / end pointers |
| Element stride | **4** (`>> 2`) |
| This call | count=`0` → shrink-to-empty when non-empty |

---

## 6. Callers (own VA xrefs only)

| Site | Function | Pre-call pattern (CF) |
|------|----------|------------------------|
| `0x0092f136` | `FUN_0092f120` / `Client_MaybeRefreshEquipGfxHost` | **`jmp`** tail: `client+0xE04` → `+0xE898` → ECX |
| `0x00937623` | `FUN_00937560` | `+0xE04` → `+0xE898` → ECX |
| `0x00943128` | `FUN_009430f0` | same |
| `0x00943bac` | `FUN_00943b80` | same |
| `0x0094403e` | `FUN_00943fb0` | same |
| `0x0094474f` | `FUN_009440e0` (CompletelyDestroyObject family) | same |
| `0x00949377` | `FUN_009492d0` | same |
| `0x00949464` | `FUN_009493c0` | same |
| `0x004c5edd` | `CVOGCreature_PostCreateFromPacket` | resolve `+0xE898` → ECX |
| `0x004ff332` | `FUN_004fedc0` (equip-from-create / weapon attach path) | `+0xE898` → ECX |
| `0x00521425` | `FUN_00521310` | `+0xE898` → ECX |
| `0x00584312` | `FUN_00584290` | `+0xE898` → ECX |
| `0x00954d21` | (site; function label weak) | `edi+0xE04` → `+0xE898` → ECX |

**Caller role summary:** optional **gfx-host list flush** after equip/create/destroy/client UI transitions — **not** the equip logic itself.

---

## 7. Naming

| Claim | Confidence |
|---|---|
| Role: flag-gated clear of host vector `+0xA8` | **High** |
| Chain name under equip gfx host refresh | **Probable** (parent dual + equip callers) |
| `EquipGfxHost_ClearListIfFlag_Inferred` | **Probable / Inferred** |
| Product symbol | **Open** |

---

## 8. Gaps

1. Product / RTTI name of host type and of vector elements at `+0xA8`.
2. English of flag `+0x53` (dirty bit vs enable vs “has list”).
3. Full dual of `FUN_004367f0` / element destructor path (`FUN_00410490`).
4. Runtime / bit-exact image verification.
5. Whether any path **sets** `+0x53` immediately before this call (producer graph).

**Verdict:** **accept-with-gaps** — machine CF + ABI + gate + `+0xA8` this-adjust + clear-on-zero sealed; product names and element semantics open.
