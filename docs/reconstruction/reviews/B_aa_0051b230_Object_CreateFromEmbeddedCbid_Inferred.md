# Review B (skeptical / adversarial): `aa_0051b230` Object_CreateFromEmbeddedCbid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b230` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9R-H) |
| **Counterpart** | `reviews/A_aa_0051b230_Object_CreateFromEmbeddedCbid_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function is `__fastcall` with int arg | **Falsified** — `MOV EDI,ECX`; call sites only bind ECX via this-adjust LEA |
| 2 | Callers pass RTTI args into this function | **Falsified** — RTTI pushes feed **following** `__RTDynamicCast` (`0x004898a4`); `ADD ESP,0x14` cleans 5 cast args |
| 3 | Identical to `AllocateNewObjectFromCbid` | **Partial** — same factory/init family; **different** host (self fields vs sector map), no template loop, no failure plate |
| 4 | GiveItemByCbid is one-arg only | **Falsified** — image `PUSH 0; PUSH cbid; ADD ESP,8` |
| 5 | `FUN_00516720` is free function of one string | **Falsified** — thiscall ECX=obj, stack=string |
| 6 | This is a skill-bank cast helper | **Overstated** — no skill strings; object spawn virtual; only WQ-009 residual by address/partition proximity |
| 7 | Product English known | **Overstated** — `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI / return obj* | **High** | Wrong port calling convention |
| CBID source `*(this+0xA8)+0x34` | **High** | Wrong spawn id |
| Init order vtbl+8 → +0xB8 → name → +0xC4 | **High** | Missing object setup |
| Descriptor type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against creature caller (`FUN_004c8f00`)

```
; this-adjust into cloned-object subobject
LEA  ECX, [ECX+EDI*1+0xfffffb04]
CALL 0x0051b230          ; THIS unit — returns base obj*
PUSH EAX
CALL __RTDynamicCast     ; → CVOGCreature*
… Skill_EnsureLoadedInTree walk on success …
```

Confirms role: **spawn base clone, then typed cast and creature-specific skill bank load** — skill coupling is in the **caller**, not this VA.

---

## 4. Surviving contract for AutoCore

```
// Port as virtual method on CVOGClonedObjectBase-like host:
obj = Object_CreateFromEmbeddedCbid_Inferred(self);
// Must call GiveItemByCbid(cbid, 0) with cbid from *(*(self+0xA8)+0x34).
// Must run vtbl+8(cbid, *(self+0xA4), 1), vtbl+0xB8(*(self+0xB8)),
// FUN_00516720(obj, *(self+0x158)), copy +0xC4.
// Return NULL if factory fails; do not cast here.
// Keep separate from AllocateNewObjectFromCbid (sector-map host).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, factory args, init chain, and cast-site separation. Product/descriptor residual → **accept-with-gaps**.
