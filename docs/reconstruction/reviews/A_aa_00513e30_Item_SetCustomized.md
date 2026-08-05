# Review A (reconstruction fidelity): `aa_00513e30` Item_SetCustomized

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513e30` |
| **VA** | `0x00513e30` |
| **Canonical name** | `Item_SetCustomized` (proposed; was `FUN_00513e30`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_00513e30_Item_SetCustomized.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** — **mask `0x100000` / bit 20 sealed** |

---

## 1. Purpose

**Per-item Customized flag setter.** Writes bit **20** (mask **`0x100000`**) of `item+0x17c` to match the caller’s desired 0/1 value. On value change, marks the object (and `+0xac` chain) dirty via `FUN_00512670` (`| 0x20000`). **No** post-write vtable notify (unlike `Item_SetBroken`).

**Calling convention (bytes):** `this` in **ECX**; one stack arg (desired, low byte); **`ret 4`**.

| Slot | Role | Evidence |
|------|------|----------|
| `this` / `param_1` (ECX) | `Item*` / cloned object | `mov eax,[ecx+0x17c]`; `xor [ecx+0x17c],esi` |
| stack arg | desired Customized (bool-ish) | `movzx esi, byte [esp+8]` after `push esi` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00513e30_FUN_00513e30.md` |
| Annotated | `docs/reconstruction/raw/aa_00513e30_FUN_00513e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_SetCustomized.cpp` |
| Function record | `docs/reconstruction/functions/aa_00513e30_FUN_00513e30.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x00513e30` — **≡ raw body** |
| Live bytes | Ghidra `read_memory` 64 B @ `0x00513e30` — ends `c2 04 00` + `CC` |
| Dirty helper | `FUN_00512670` @ `0x00512670` |
| Sibling Broken setter | `Item_SetBroken` `0x00513de0` (mask `0x80000` + vtbl) |
| Peer duals | permanent customize `aa_00941b20`; trade drop `aa_00860a50` |

**Not performed:** `disassemble_bytes` (policy), Launcher, live CE, bit-exact image diff.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Load flags `@item+0x17c` | **Yes** (`8b 81 7c 01 00 00`) |
| Zero-extend desired low byte | **Yes** (`0f b6 74 24 08`) |
| Compare `(flags >> 0x14) & 1` vs desired byte | **Yes** |
| On inequality → `FUN_00512670` | **Yes** (`e8 25 e8 ff ff` → `0x00512670`) |
| XOR set-bit formula with mask **`0x100000`** | **Yes** (`81 e6 00 00 10 00`) |
| No vtbl tail | **Yes** — fallthrough `pop esi; ret 4` |
| Function boundary `00513e30`–`00513e63` | **Yes** |

### Closed form (sealed)

```text
// ECX = Item*; stack = desired (low byte used)
if (((flags[+0x17c] >> 20) & 1) != (desired & 0xff))
  Item_MarkFlagsDirty(this);          // FUN_00512670: | 0x20000 on self + +0xac chain

// set bit20 := (desired & 1)
flags ^= (((desired & 0xff) << 20) ^ flags) & 0x100000;
return;  // ret 4
```

### Mask **`0x100000`** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Decompile | `& 0x100000` on the XOR write path |
| Bytes | `81 e6 00 00 10 00` = `and esi, 0x00100000` (LE imm) |
| Bit index | `shr 0x14` / `shl 0x14` → bit **20** = `1 << 20` = `0x100000` |

---

## 4. Product English (external peer evidence)

This unit **owns the write mask and CF**. Product label **Customized**:

| Source | Detail |
|--------|--------|
| Trade drop `0x00860a50` | Rejects bit20; string `"You cannot trade items that have been customized to you!"` |
| Permanent customize Yes | `0x0091260e` / modal case `0x4e58`: `FUN_00513e30(1)` then re-confirm equip |
| Sibling dual `aa_00513de0` | Documents this as bit-20 sibling setter |

Role name **Probable / High** via that chain; original PDB still open.

---

## 5. Sibling pattern

| VA | Role | Mask / bit |
|----|------|------------|
| `0x00513de0` | Broken setter | `0x80000` / bit 19 + vtbl `+0x90` if set |
| `0x00513e30` | **This unit** — Customized setter | `0x100000` / bit 20; dirty same; **no** vtbl |
| `0x00513e70` | `Item_IsStackEligible` | **reads** bit 19; no write |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Function boundary + `ret 4` | **High / Sealed** |
| ECX = item; 1 stack arg | **High / Sealed** |
| Write mask **`0x100000`** = bit 20 | **High / Sealed** |
| Dirty on change via `FUN_00512670` | **High / Sealed** |
| No vtbl side effect | **High / Sealed** |
| Role = Customized setter | **Probable / High** (peer string + path) |
| Full caller census | Open (xrefs sampled) |
| Original PDB symbol | Open |
| Overall | **Probable / accept-with-gaps** |

---

## 7. Verdict

### **accept-with-gaps**

**Accept:** Live body matches raw; bytes seal mask **`0x100000`**, bit index **20**, dirty-on-change, and clean return (no virtual). Role as Customized setter matches peer trade/customize duals.

**Gaps:** original symbol; exhaustive callers; whether non-0/1 desired values are passed; runtime/diff.
