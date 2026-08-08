# Review B (skeptical / adversarial): `aa_00416240` FieldBlock_CopyFrom_ClearFlags0xBC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9I-H) |
| **Counterpart** | `reviews/A_aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Full POD memcpy of object | **Falsified** — only clears one dword + calls selective `FUN_00416160` |
| 2 | Pre-clear of `+0xBC` changes which ranges copy | **Narrowed** — `FUN_00416160` **unconditionally** writes `dest[0x2f]=src[0x2f]` then gates on **src’s** flags; pre-clear is overwritten for non-alias case |
| 3 | Shopveh / drive UI function | **Falsified** — scaffold chain name only; no string/RTTI at this VA; callers are object-swap + mesh path |
| 4 | cdecl / no stack cleanup | **Falsified** — `RET 4` / thiscall |
| 5 | Void return | **Falsified** — `MOV EAX,ESI` returns dest |
| 6 | Leaf | **Falsified** — calls `FUN_00416160` |
| 7 | Constructor of host class | **Falsified** — no vtbl install; pure assign wrapper |
| 8 | Same as bare `FUN_00416160` | **Shape related, identity no** — extra clear + return dest; different call sites use both |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear + copy + return dest | **High** | Wrong assign path |
| RET 4 / thiscall | **High** | ABI break |
| Flag dword offset 0xBC | **High** | Wrong field |
| Pre-clear product motive | **Low** | Over-document dead store |
| Field-block English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00416160 (evidence):
//   always copy [0x20..0x29], byte@0x2e, flags@0x2f from src
//   if (!(flags&1)) copy dwords[0..0xF]
//   if (!(flags>>1&1)) copy dwords[0x10..0x1F]
//   if (!(flags>>2&1)) copy [0x2a..0x2c]
//   dest[0x2d]++
// This FUN_00416240:
//   dest+0xBC = 0; FUN_00416160(dest,src); return dest
// Caller 00833160: temp = CopyClear(ESI+0x510); copy EDI→ESI; copy temp→EDI  (swap)
```

Live decompile 2026-08-05 ≡ scaffold 2026-07-23; 29 B hex seals CF.

---

## 4. Surviving contract for AutoCore

```
// Port as thin wrapper only:
void* FieldBlock_CopyFrom_ClearFlags0xBC(void* dest, const void* src) {
  *(uint32_t*)((uint8_t*)dest + 0xBC) = 0;
  SelectiveFieldBlock_Assign(dest, src); // FUN_00416160
  return dest;
}
// Do not invent full-object memcpy, shopveh UI, or independent flag policy.
// Pair with FUN_00416160 dual (WQ9I-G) for range map.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/callers. Rejects shopveh plate and “clear controls copy ranges” overclaim. Residual product + callee dual → **accept-with-gaps**.
