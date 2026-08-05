# Review B (skeptical / adversarial): `aa_00518940` Object_SharedBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-B) |
| **Counterpart** | `reviews/A_aa_00518940_Object_SharedBase_Ctor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is GiveItem / reaction-specific helper | **Falsified** — 30+ ctor/factory callers across creature/vehicle/character/bases |
| 2 | `this` is always complete-object base 0 | **Falsified** — image LEAs embed at `+0x40`/`+0xe0`/`+0x110`/`+0x500`/`+0x670` |
| 3 | Function installs Creature/Vehicle primary vtbl | **Falsified** — no store of creature/vehicle vtbl immediates; only CS helper vtbls |
| 4 | `FUN_00512670` is unrelated / optional | **Falsified** — always called; establishes dirty bit `0x20000` on `+0x17c` |
| 5 | Clean invents networking serialize | **Falsified** — field init + CS only |
| 6 | Stack args exist (`ret N`) | **Falsified** — epilogue `add esp,0x10; ret` is SEH frame only |
| 7 | Name must be `CVOGObject_ctor` exactly | **Open residual** — role High; retail symbol unproven; keep Inferred product English |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Shared-base field ctor role | **High** | Mis-place in hierarchy |
| Embed offsets per type | **High** | Wrong `this` when porting outer ctors |
| TFID invalid source | **High** | Bad sentinel compares |
| Dirty flag path | **High** | Miss net-dirty defaults |
| Product class string | Medium | Naming only |
| All bit meanings in `0x22210` | Medium | Flag parity |

---

## 3. Cross-check against raw + bytes

```
SEH
defaults… +0x90=DAT_00b04370… +0xb8=1.0f
+0x160=invalid TFID; +0x184&=~0xf
+0x17c=(x&0xffe22210)|0x22210
zero +0x80..
FUN_00512670(this)          // |0x20000
+0x28..=-1
+0xb0 = new(0x2c)? CS_init : 0
+0x40=invalid TFID
DAT_00b04200++; first→zero globals
return this
```

Outer Creature spine (already dual-sealed elsewhere):

```
if mostDerived:
  cookies @ +4/+0x44
  Object_SharedBase_Ctor(ecx=this+0x500)
FUN_005c82a0(this, 0)
install creature vtbls…
```

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — client object core subobject
ObjectCore Object_SharedBase_Ctor(ObjectCore self)
{
    // defaults, invalid TFIDs, +0xb8=1f, flag mask
    self.Flags = (self.Flags & 0xffe22210) | 0x22210;
    Object_PropagateDirtyBit0x20000(self); // |0x20000; walk +0xac
    self.CsHelper = AllocCriticalSectionHelper_0x2c(); // may null
    self.TfidA = InvalidTfid;
    g_ObjectInstanceCount++;
    if (g_ObjectInstanceCount == 1) ClearFirstInstanceGlobals();
    return self;
}
// Outer most-derived ctors pass subobject pointer, not always base 0.
```

Do **not** invent full Creature/Vehicle construction here. Do **not** treat weak GiveItem callee name as identity.

---

## 5. Open questions

1. Retail RTTI / product class string for this core.
2. Whether server AutoCore needs CS helper parity.
3. Full enumeration of default flag bits in `0x22210`.

**Verdict:** **accept**
