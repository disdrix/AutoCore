# Review A (reconstruction fidelity): `aa_00513de0` Item_SetBroken

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513de0` |
| **VA** | `0x00513de0` |
| **Canonical name** | `Item_SetBroken` (proposed; was `FUN_00513de0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_00513de0_Item_SetBroken.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** — **mask `0x80000` / bit 19 sealed** |

---

## 1. Purpose

**Per-item Broken flag setter.** Writes `ItemFlag_Broken` at `item+0x17c` bit **19** (mask **`0x80000`**) to match the caller’s desired 0/1 value. On value change, marks the object (and `+0xac` chain) dirty via `FUN_00512670` (`\| 0x20000`). If Broken is **set** after the write, **tail-jumps** to vtable slot `+0x90` with stack arg forced to **0**.

**Calling convention (bytes):** `this` in **ECX**; one stack arg (desired broken, low byte); **`ret 4`**.

| Slot | Role | Evidence |
|------|------|----------|
| `this` / `param_1` (ECX) | `Item*` / cloned object | `mov eax,[ecx+0x17c]`; `xor [ecx+0x17c],esi` |
| stack arg | desired Broken (bool-ish) | `movzx esi, byte [esp+8]` after `push esi` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00513de0_FUN_00513de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513de0_FUN_00513de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_SetBroken.cpp` |
| Function record | `docs/reconstruction/functions/aa_00513de0_FUN_00513de0.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x00513de0` — **≡ raw body** |
| Live bytes | Ghidra `read_memory` 80 B @ `0x00513de0` — ends `c2 04 00` + `CC` |
| Dirty helper | `FUN_00512670` @ `0x00512670` (decompile) |
| Sibling bit-20 setter | `FUN_00513e30` (mask `0x100000`, no vtbl tail) |
| Peer reader | `Item_IsStackEligible` `0x00513e70` (inline bit19 test) |
| Registry | `NAMING_REGISTRY` `ItemFlag_Broken` → setter `0x00513de0` |
| Cross duals | CountItemsByCbid / FindItemByCbid Broken seals |

**Not performed:** `disassemble_bytes` (policy), Launcher, live CE, bit-exact image diff, full xref crawl (decompile/read_memory only this unit).

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Load flags `@item+0x17c` | **Yes** (`8b 81 7c 01 00 00`) |
| Zero-extend desired low byte | **Yes** (`0f b6 74 24 08`) |
| Compare `(flags >> 0x13) & 1` vs desired byte | **Yes** |
| On inequality → `FUN_00512670` | **Yes** (`e8 …` → `0x00512670`) |
| XOR set-bit formula with mask **`0x80000`** | **Yes** (`81 e6 00 00 08 00`) |
| `test byte [ecx+0x17e], 8` (= bit 19 of dword) | **Yes** |
| If set: force stack arg 0, `jmp [vtable+0x90]` | **Yes** (not `call`) |
| Else / fallthrough: `ret 4` | **Yes** (`c2 04 00`) |

### Closed form (sealed)

```text
// ECX = Item*; stack = desired (low byte used)
if (((flags[+0x17c] >> 19) & 1) != (desired & 0xff))
  Item_MarkFlagsDirty(this);          // FUN_00512670: | 0x20000 on self + +0xac chain

// set bit19 := (desired & 1)   [only bit0 of desired affects write]
flags ^= (((desired & 0xff) << 19) ^ flags) & 0x80000;

if (flags & 0x80000)                  // post-write Broken set
  return this->vtbl[+0x90](0);        // tail jmp; stack arg overwritten with 0
return;
```

### Mask **`0x80000`** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Decompile | `& 0x80000` on the XOR write path |
| Bytes | `81 e6 00 00 08 00` = `and esi, 0x00080000` (LE imm) |
| Bit index | `shr 0x13` / `shl 0x13` → bit **19** = `1 << 19` = `0x80000` |
| Post-test | `test [ecx+0x17e], 8` → byte@`+0x17e` bit3 = dword bit19 |
| Registry / peers | `ItemFlag_Broken`; CountItemsByCbid; stack eligibility |

---

## 4. Dirty helper (`FUN_00512670`) — in-scope callee only

```c
// sets item+0x17c |= 0x20000, then walks *(item+0xac) chain same OR
void __fastcall FUN_00512670(int item);
```

Called **only when** current Broken bit differs from desired low-byte value. Not a Broken clear/set itself (bit 17 / mask `0x20000`).

---

## 5. Sibling pattern (context, not owned)

| VA | Role | Mask / bit |
|----|------|------------|
| `0x00513de0` | **This unit** — Broken setter | `0x80000` / bit 19 + vtbl `+0x90` if set |
| `0x00513e30` | Adjacent bit-20 flag setter | `0x100000` / bit 20; dirty same; **no** vtbl |
| `0x00513e70` | `Item_IsStackEligible` | **reads** bit 19; no write |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Function boundary (`00513de0`–`00513e2c`, `ret 4`) | **High / Sealed** |
| ECX = item; 1 stack arg; `ret 4` | **High / Sealed** |
| Write mask **`0x80000`** = bit 19 | **High / Sealed** |
| Role = Broken setter | **High / Sealed** (string/overlay evidence owned by peer duals + registry) |
| Dirty on change via `FUN_00512670` | **High / Sealed** (CF + callee body) |
| Post-set vtbl `+0x90` tail with arg 0 | **High / Sealed** (bytes) |
| Product name of vtbl `+0x90` | Tentative / Open |
| Full caller census | Open (not re-owned; sample xrefs in raw peers) |
| Original PDB symbol | Open |
| Overall | **Probable / accept-with-gaps** |

---

## 7. Verdict

### **accept-with-gaps**

**Accept:** Live body matches raw; bytes seal mask **`0x80000`**, bit index **19**, dirty-on-change, and post-set virtual tail. Role as `ItemFlag_Broken` setter matches registry and peer duals.

**Gaps:** vtbl `+0x90` product name; complete caller list; whether non-0/1 desired values are ever passed; runtime/diff.
