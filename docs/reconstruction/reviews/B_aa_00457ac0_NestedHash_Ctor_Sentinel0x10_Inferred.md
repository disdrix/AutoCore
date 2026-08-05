# Review B (skeptical / adversarial): `aa_00457ac0` NestedHash_Ctor_Sentinel0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457ac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-E) |
| **Counterpart** | `reviews/A_aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — stack self; `RET 4` |
| 2 | Decompiler void/no-arg signature complete | **Falsified** — placement ctor returns self |
| 3 | Freeing ctor / dtor | **Falsified** — no delete; returns self |
| 4 | gfxDeviceIB-only (scaffold name) | **Falsified** — 5 callers incl. statics and heap; reject `Named_gfxDeviceIB_*` |
| 5 | Identical to 0x14 twin including node size | **Partial** — CF/bytes identical except sentinel CALL target (0x10 vs 0x14) |
| 6 | Node is 0x28 like Ass NestedHash | **Falsified** — `FUN_004397f0` is `new(0x10)` |
| 7 | Product “Hash” English | **Careful** — structural `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong convention |
| Layout +8..+0x24 | **High** | Misaligned members |
| Node size 0x10 | **High** | Wrong node payload |
| Multi-caller reuse | **High** | Over-specializing name |
| Product English | **Low** | Naming only |
| Flags | **Med** | Field meaning |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

Byte body is twin of `0043bdf0` except:
- `e8101dfeff` → `FUN_004397f0`
- `e8ddcb0000` → `FUN_004646e0`

Callers construct statics (`DAT_00d1fd18` / `d1fcec` / `d1fcc0`), heap `0x30` hosts, and stack bag in `FUN_0098fef0` (gfxDeviceIB string path is caller-side only).

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
NestedHash10* ctor(NestedHash10* self) {
  self->sentinel = AllocCircularSentinel_0x10();  // FUN_004397f0
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// Reusable bag — do not hard-wire single product host.
// Distinguish from Sentinel0x14 twin and Ass 0x28 NestedHash.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/node size/multi-caller. Residual product plates + unwritten head + flags → **accept-with-gaps**.
