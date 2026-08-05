# Review A (reconstruction fidelity): `aa_005142a0` Item_GetStoreSellPrice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005142a0` |
| **VA** | `0x005142a0` |
| **Canonical name** | `Item_GetStoreSellPrice_Inferred` |
| **Prior names** | `FUN_005142a0`, `Named_CalleeOf_…_005142a0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Reviewer role** | Independent reconstruction review (raw ≡ live ≡ full body bytes) |
| **Counterpart** | `reviews/B_aa_005142a0_Item_GetStoreSellPrice_Inferred.md` |
| **System** | `inventory-transfer` (vendor sell value) |
| **Dual status** | **Present** (first dual seal) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Compute vendor sell price (credits int)** for an inventory **item** in ECX.

```text
int __thiscall Item_GetStoreSellPrice_Inferred(Item* this)
{
    Clonebase* cb = *(this + 0xA8);
    if (*(cb + 0x3C) == 0)
        Clonebase_EnsureDefLoaded(cb, /*phy*/0, /*name*/1);  // FUN_004f1e20

    def = *(*(this + 0xA8) + 0x3C);
    if (def != 0 && *(int32*)(def + 0x3B4) != 1)
        return 0;   // not store-wanted → zero price

    // else null def OR flag==1 → compute:
    base = FUN_00513580(this) + *(int32*)(this + 0xC4);
    // FUN_00513580: sum of equipped-mod/component values at component+0x94
    price = (int)( (float)base * 0.1f );          // DAT_009ce128 = 0x3DCCCCD0
    if ((*(uint8*)(this + 0x17E) & 0x08) != 0)
        price = (int)( (float)price * 0.5f );     // DAT_00a0f298 = 0x3F000000
    if (price < 1)   // asm: if !(price > 0) → 1
        price = 1;
    return price;
}
```

Sibling of `Item_IsWantedByStore_Inferred` (`0x00513770`): same ensure + **inverse** use of `def+0x3B4==1` (want → bool; here want-fail → **0** price).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005142a0_FUN_005142a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005142a0_FUN_005142a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005142a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005142a0_FUN_005142a0.md` |
| Live decompile | Ghidra `0x005142a0` ≡ raw |
| Live full body | `read_memory` `0x005142a0` + `0x005142d0` through `ret` |
| Float constants | `read_memory` `0x009ce128` → `d0 cc cc 3d` = **0.1f**; `0x00a0f298` → `00 00 00 3f` = **0.5f** |
| Entry / ensure | `get_assembly_context` `0x005142a0`: `mov esi,ecx; … push 1; push 0; call FUN_004f1e20` |
| Caller sell | `FUN_00587970` @ `0x00587998`: want-check then this × qty vfunc → `CVOGCharacter_AddCredits` |
| Sibling dual | `aa_00513770` Item_IsWantedByStore_Inferred |
| Component sum | live decompile `FUN_00513580` (sum `+0x94` over mods) |

**Not performed:** `disassemble_bytes`, Launcher, golden price table capture.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| ECX `this` | Item* | entry `push esi; mov esi,ecx`; callers `mov ecx,esi` (item) |
| stack | none | plain `ret` |
| EAX return | int32 credits (0 or ≥1) | body |

Decompiler sometimes labels `__fastcall`; bytes are standard **MSVC thiscall** (ECX only).

---

## 4. Control flow + formula: live ≡ raw (bytes)

### 4.1 Gate

```text
005142a0  push esi / mov esi, ecx
          mov ecx, [esi+0xa8]
          cmp dword [ecx+0x3c], 0
          jnz skip_ensure
          push 1 / push 0 / call FUN_004f1e20
skip_ensure:
          mov eax, [esi+0xa8] / mov eax, [eax+0x3c]
          test eax, eax
          jz compute                 ; null def → still price
          cmp dword [eax+0x3b4], 1
          setz al / test al, al
          jnz compute
          xor eax, eax / pop esi / ret   ; unwanted → 0
```

### 4.2 Price (SEALED)

```text
compute:
          mov ecx, esi
          call FUN_00513580          ; component value sum
          add eax, [esi+0xc4]        ; + item base value field
          test byte [esi+0x17e], 8   ; half-price flag (ZF preserved across SSE)
          cvtsi2ss xmm0, eax
          mulss xmm0, [0x009ce128]   ; * 0.1
          cvttss2si eax, xmm0        ; truncate toward 0
          jz no_half                 ; flag bit clear
          cvtsi2ss xmm0, eax
          mulss xmm0, [0x00a0f298]   ; * 0.5
          cvttss2si eax, xmm0
no_half:
          test eax, eax
          jg done
          mov eax, 1                 ; floor at 1
done:     pop esi / ret
```

**Note:** SSE mul/cvt do **not** clobber ZF from the earlier `test byte …, 8`, so the half-price `jz` is correct.

---

## 5. Offsets

| Offset | Object | Role | Conf |
|-------:|--------|------|------|
| `+0xA8` | item | clonebase* | **High** |
| clonebase `+0x3C` | cb | def* | **High** |
| def `+0x3B4` | def | vendor-want flag (`==1`) | **High** |
| item `+0xC4` | item | base value addend (int) | **High** CF; English **Probable** |
| item `+0x17E` bit3 | item | half-price / condition flag | **High** CF; English **Probable** |

---

## 6. Callers (sample)

| Site | Role |
|------|------|
| `FUN_00587970` | store sell: want → price → qty × price → AddCredits |
| `FUN_00587c00` | related store path |
| `FUN_0084b770` / `FUN_0088f500` / `FUN_008c03c0` / `FUN_008e55e0` | UI/tooltip/mission money display family |
| `FUN_0040f4e0` | other pricing helper |

---

## 7. Confidence

| Claim | Confidence |
|---|---|
| thiscall Item* → int price | **High** |
| ensure `(0,1)` + `+0x3B4` gate | **High** |
| formula `floor_trunc(base*0.1)` optional `*0.5`, min 1 | **High** (bytes + float mem) |
| null def still prices (permissive) | **High** |
| `FUN_00513580` = mod value sum | **High** CF; type English **Probable** |
| Product symbol / economy table seal | **Open** |
| Runtime golden | **Open** |

---

## 8. Gaps

1. Exact English of item `+0xC4` (base sell vs base cost).
2. Flag `+0x17E&8` product meaning (damaged / quest / faction?).
3. Full dual of `FUN_00513580` component enumeration.
4. Whether UI displays pre- or post-half value consistently.

**Verdict:** **accept-with-gaps**
