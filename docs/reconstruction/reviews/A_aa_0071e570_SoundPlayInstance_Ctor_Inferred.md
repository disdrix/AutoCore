# Review A (reconstruction fidelity): `aa_0071e570` SoundPlayInstance_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071e570` |
| **VA** | `0x0071e570` |
| **Canonical name** | `SoundPlayInstance_Ctor_Inferred` |
| **Ghidra symbol** | `FUN_0071e570` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0071e570_SoundPlayInstance_Ctor_Inferred.md` |
| **System** | client audio / `CSoundManager` / SpecialFX play instance |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Constructor / field filler** for a **`0x150`-byte play instance** allocated by `FUN_00723120` (`operator_new(0x150)` → this VA → list push).

Authoritative stores (live ≡ raw; **`EAX = this`** object):

| Dest (dword index) | Byte offset | Source |
|---|---|---|
| `this[0x4E]` | `+0x138` | `param_8` |
| `this[0x4A..0x4D]` | `+0x128..+0x134` | `param_3..param_6` |
| `this[4..7]` | `+0x10..+0x1C` | `*param_2` four dwords (TFID / id block) |
| `this[0]` | `+0x00` | `XMM0` float (`in_XMM0_Da`) |
| `this[1]` | `+0x04` | `param_7` |
| `this[0x4F]` | `+0x13C` | **0** |
| `this[0x50]` | `+0x140` | **0** |
| name @ `this+0x20` | `+0x20` | C-string copy from `param_1` (ECX) until NUL |
| `this[2]` | `+0x08` | `param_9` |
| `*(byte*)(this+0x51*4)` | `+0x144` | **0** |

**Leaf** — no callees. Single caller: **`FUN_00723120`** (`CSoundManager_AllocPlayInstance_Inferred`) at `0x00723171`.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_0071e570_*` | CF ≡ live |
| Live decompile | Ghidra `0x0071e570` | sealed |
| Complete analysis | leaf; 1 xref | |
| Parent dual | `A_aa_00723120_CSoundManager_AllocPlayInstance_Inferred` | new(0x150)→ctor→push |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf | **Confirmed** | |
| `this` in **EAX** (MSVC new→ctor) | **Confirmed** | `in_EAX`; parent dual |
| Name strcpy to **`+0x20`** | **Confirmed** | `0x20 - (int)param_1` index trick |
| TFID-like 16 bytes at **`+0x10`** | **High** | four dwords from `param_2` |
| Clear `+0x13C/+0x140`, flag byte `+0x144=0` | **Confirmed** | |
| XMM0 → `+0` float field | **High** | decompiler `in_XMM0_Da` |
| Exact semantic of param_3..9 (pos vs type vs flags) | **Medium** | parent stack remap residual |
| Fits in 0x150 object | **High** | highest store `+0x144` |
| Product English name | **Probable** | inferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Field pack from stack/reg | Yes |
| Name copy to +0x20 | Yes |
| Zero two dwords + flag byte | Yes |
| No branches | Yes |

```c
// void SoundPlayInstance_Ctor(Instance *eax_this, char *name, uint32_t *id16, ...)
void FUN_0071e570(char *name, uint32_t *id16,
                  uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                  uint32_t e, uint32_t f, uint32_t g)
{
  this[0x4E] = f;
  this[0x4A] = a; this[0x4B] = b; this[0x4C] = c; this[0x4D] = d;
  this[4] = id16[0]; this[5] = id16[1]; this[6] = id16[2]; this[7] = id16[3];
  this[0] = xmm0;
  this[1] = e;
  this[0x4F] = 0; this[0x50] = 0;
  // strcpy(this+0x20, name)
  this[2] = g;
  *((uint8_t *)this + 0x144) = 0;
}
```

---

## 5. Callers / callees

**Callees:** none.

**Callers:** `FUN_00723120` only (SpecialFX alternate play path from `FUN_004b7e50`).

---

## 6. Gaps / open

1. Full ABI matrix vs `00723120` / `004b7e50` call sites (which stack slot is world pos, type, etc.).
2. Whether object is same family as 0x160 freelist queue slots (different size → **distinct**).
3. Runtime not run.

**Verdict:** **accept-with-gaps** — field map and ctor role sealed; param semantics residual.
