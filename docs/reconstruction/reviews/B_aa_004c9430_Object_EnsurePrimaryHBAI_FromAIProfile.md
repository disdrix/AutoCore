# Review B (skeptical / adversarial): `aa_004c9430` Object_EnsurePrimaryHBAI_FromAIProfile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-I) |
| **Counterpart** | `reviews/A_aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md` |
| **Scratch** | `tmp/a_004c9430.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / no stack cleanup | **Falsified** — epilogue `C2 08 00` (`RET 8`) |
| 2 | Always starts HB | **Falsified** — `param_2==0 && host+0x7e` → `CVOGHBBase_Stop` |
| 3 | Switch is AICode 1..6 CreateByAICode | **Falsified** — profile node word +0x10 cases 2..5 + default; sizes 0xB0/0xC0 not AI factory table |
| 4 | No secondary path | **Falsified** — def `+0x4e8==1` → `new(0x28)` + `FUN_005d6b80` |
| 5 | Leaf / no list | **Falsified** — `CVOGHBList_Enqueue` + Start/Stop |
| 6 | Product name is retail plate | **Overstated** — no plate string; structural name only |
| 7 | Early return is meaningful ExceptionList API | **Residual** — SEH frame; do not port as intentional ExceptionList return |
| 8 | Always refreshes skills | **Falsified** — only when clone type `+0x38 != 0x14` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 8 | **High** | ABI break |
| +0x1fc primary slot | **High** | Double-create / skip |
| Factory type table | **High** | Wrong HBAI subclass |
| Start vs Stop policy | **High** | Dormant vs live HB |
| Secondary +0x4e8 | **High** | Missing period HB |
| Product type English | **Low/Open** | Naming only |
| Early-out EAX | **Medium residual** | SEH surface |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall Object_EnsurePrimaryHBAI_FromAIProfile(self, deferStop, key)
if self+0x1fc: return (epilogue)
key = key==-1 ? def+0x4dc : key
it = lower_bound(AIProfileMap, key); if end: return
self+0x200 = 1<<(type&0x1f)
hb = construct_by_type(type)  // 2,3,4,5,default
install / enqueue / start-or-stop
optional secondary FUN_005d6b80
maybe skill refresh if type!=0x14
RET 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Jump table bytes seal cases 2..5. Callees dual-sealed for map + HB list.

---

## 4. Surviving contract for AutoCore

```
// Host object spawn / AI attach path:
if (!obj->primaryHB) {
  Object_EnsurePrimaryHBAI_FromAIProfile(obj, deferStopFlag, profileKeyOrMinus1);
}
// Ports must:
//  - honor already-present gate at +0x1fc
//  - map profile type word -> correct subclass sizes (0xB0/0xC0) and ctors
//  - enqueue on host CVOGHBList before Start
//  - implement Stop path when deferStop==0 && host.flag_0x7e
//  - optional secondary HB when def+0x4e8==1
//  - skill refresh when clone type != 0x14
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/factory/list policy. Remaining gaps are product type English, SEH early-return residual, and DATA-only callers → **accept-with-gaps**.
