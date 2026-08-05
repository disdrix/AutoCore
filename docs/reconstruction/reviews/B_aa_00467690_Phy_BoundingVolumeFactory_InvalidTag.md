# Review B (skeptical / adversarial): `aa_00467690` Phy_BoundingVolumeFactory_InvalidTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467690` |
| **VA** | `0x00467690` |
| **Canonical name** | `Phy_BoundingVolumeFactory_InvalidTag` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00467690_Phy_BoundingVolumeFactory_InvalidTag.md` |
| **System** | `physics` / `phyBoundingVolumeFactory` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is **only** an invalid-tag logger / assert | Body has five success alloc/dispatch arms before any log | **Falsified** — primary role is FOURCC factory |
| 2 | Every invalid tag logs `"Invalid tag [ %s ]…"` | Log sits under `param_1 == 0` only; other unknowns fall through to null | **Falsified** — null-only log |
| 3 | Tags are numeric `1..5` like CreateFromTag | Body CMPs `0x4256xxxx` FOURCCs; only BVSP *calls* CreateFromTag with **1** | **Falsified** for input domain |
| 4 | BVSP inlines sphere `new(0x18)` here | Asm: `mov ecx,1` + call `0x00467820`; alloc is inside CreateFromTag | **Falsified** inline — **delegates** |
| 5 | BVBX/BVCP/BVWS/BVSF also go through CreateFromTag | Separate `operator_new` + local ctors; no call to `00467820` | **Falsified** for those tags |
| 6 | FOURCC byte order is file-order `PSVB` mnemonic | Imm `0x42565350` = `('B'<<24)\|('V'<<16)\|('S'<<8)\|('P')` classic BE-FOURCC **BVSP**; LE dump shows `50 53 56 42` | **Attack fails** — mnemonic BVSP (and siblings BVBX/BVCP/BVSF/BVWS) |
| 7 | Human type names for all five are Confirmed from *this* body alone | This VA has no type strings; names come from sibling unserialize files | **Partial** — types High via siblings; BVSF still Medium |
| 8 | Non-null unknown tag returns non-null / default BV | Explicit fallthrough `return 0` | **Falsified** — null |
| 9 | OOM still returns constructed object | All arms gate on `new != 0` | **Falsified** — null |
| 10 | Canonical name should be CreateFromFourCC for ports | Registry / wave map pin `InvalidTag`; rename is parent policy | **Agree keep name**; document role in dual |
| 11 | clean invents CF vs raw / live | 2026-07-29 decompile ≡ raw ≡ clean stages | **Attack fails** |
| 12 | Callers only physics bone path | Xrefs: `phyBoneSharedData_unserialize` ×2 + `FUN_0095dc70` ×1 | **Attack partial** — bone + body-massage path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| FOURCC → size / ctor map (5 tags) | **Confirmed** | Wrong BV layout on port / unserialize |
| BVSP → CreateFromTag(1) only | **Confirmed** | Double-alloc or skip sphere defaults |
| Null-only invalid log | **High** | Expect logs for bad tags that never appear |
| Silent null for unknown non-null tags | **High** | Miss bad-asset diagnosis |
| Sphere/Box/Capsule/Walkable labels | **High** | Sibling string+tag asserts |
| BVSF product name | **Medium** | Misname type-4 / size-8 BV |
| `FUN_00436190` / `%s` payload for null | **Open** | Wrong log formatting in port |
| EAX ctor glue for box/capsule | **Probable** | Hooking mid-path without EAX |
| Runtime tag corpus from retail assets | **Open** | Unseen sixth tag assumption |
| Bit-exact / differential | **Open** | Project-wide defer |

---

## 3. Cross-check against raw / live / siblings

```
raw/aa_00467690 ≡ clean Phy_BoundingVolumeFactory_InvalidTag.cpp
               ≡ live decompile_function 2026-07-29

read_memory CMPs @ body:
  0x004676AF  cmp  0x42565350   // BVSP
  0x004676D0  cmp  0x42564258   // BVBX
  0x0046770C  cmp  0x42564350   // BVCP
  0x00467736  cmp  0x42565346   // BVSF
  0x00467769  cmp  0x42565753   // BVWS

BVSP arm: B9 01 00 00 00  E8 → CreateFromTag(1)

Sibling tag asserts (label evidence only; not this write-owner):
  phyBVSphere            0x42565350
  phyBVBox               0x42564258
  phyBVCapsule           0x42564350
  phyBVWalkableSurface   0x42565753

CreateFromTag (0x00467820) numeric twin (not re-reviewed here):
  1→0x18 sphere vtbl 00aa5c54
  2→0x20 FUN_00467440
  3→0x28 FUN_004674e0
  4→8   vtbl 00aa5c6c
  5→0x100 FUN_00467600
  default logs "Invalid type [ %c ]" @ line 0x66
```

### Name trap

Do **not** implement this VA as:

```c
void InvalidTag(...) { log(...); return null; }
```

Binary creates real BV objects for five tags. Ports that only implement the log arm break `phyBoneSharedData_unserialize` and the `0095dc70` caller.

### CreateFromTag trap

Do **not** replace this entire function with `CreateFromTag` alone:

- Input domain differs (FOURCC vs small int).
- Only **BVSP** forwards (as type **1**).
- Other tags allocate **here** with the same ctors CreateFromTag would use — but a blind `CreateFromTag(fourcc)` would hit the **invalid type** `%c` log path.

### Log-asymmetry trap

`CreateFromTag` default always logs. This factory logs **only** for tag `0`. Unknown FOURCCs return null quietly — do not “fix” that in a port without evidence.

### FOURCC trap

Constants are **big-endian four-character codes** as 32-bit immediates (`BVSP` = `0x42565350`). LE memory dumps spell `PSVB` — that is encoding, not the mnemonic.

---

## 4. Surviving contract for AutoCore

```
// Canonical: Phy_BoundingVolumeFactory_InvalidTag  (registry / wave6)
// Role:      Create BV from chunk FOURCC; log only if tag==0

phyBVBase* CreateFromFourCC(uint32_t tag) {
  switch (tag) {
    case 0x42565350: return CreateFromTag(1);           // BVSP sphere
    case 0x42564258: return new_ctor_box_0x20();        // BVBX
    case 0x42564350: return new_ctor_capsule_0x28();    // BVCP
    case 0x42565346: return new_ctor_type4_8();         // BVSF (name open)
    case 0x42565753: return new_ctor_walkable_0x100();  // BVWS
    case 0:
      vog_LogMessage(phyBoundingVolumeFactory.h, 0x45, 3,
                     format("Invalid tag [ %s ] for phyBoundingVolume", …));
      return nullptr;
    default:
      return nullptr;   // silent
  }
}
```

Callers that must keep working:

- `phyBoneSharedData_unserialize` (`0x00997540`) — two sites
- `FUN_0095dc70` body path — one site

---

## 5. Open questions

1. What is BVSF’s retail class name / file (`phyBV???.cpp`)?
2. Is silent-fail on unknown non-null tags intentional in source, or a decompiler/path quirk of a collapsed switch? (Body bytes support intentional: no log call on that path.)
3. Should AutoCore expose a clearer API name (`CreateFromFourCC`) while keeping the VA alias?

**Verdict:** adversarial pass does **not** overturn A’s CF map. Name is misleading; contract for ports is the FIVE-tag factory + null log. **accept-with-gaps.**
