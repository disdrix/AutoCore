# Review B (skeptical / adversarial): `aa_0074f0c0` Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074f0c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-X) |
| **Counterpart** | `reviews/A_aa_0074f0c0_Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `unaff_ESI` is decompiler noise / no formal | **Falsified** — both callers load ESI immediately before CALL; body uses `[ESI+0xc]` |
| 2 | All four vcalls use the same vtbl slot | **Falsified** — globals use **+0x10c**; host uses **+0x114** (`FF 91 0C 01 00 00` vs `FF 92 14 01 00 00`) |
| 3 | Stack thiscall / stdcall with args | **Falsified** — bare `C3`; no stack formals; this pushed only for vcalls |
| 4 | Must keep scaffold `Named_CalleeOf_Named_gfxDevice` | **Falsified** — structural name from triple global + host notify is stronger; product English still open |
| 5 | Only called from GfxDevice_Reset | **Falsified** — also `FUN_0073d8d0` vector walk (stride 0x14) |
| 6 | Globals always non-null | **Falsified** — each path tests holder != 0 and `holder+0xc` != 0 |
| 7 | Same as `FUN_0040d340` | **Falsified** — sibling uses only two globals and vtbl **+0x104**; no ESI host path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI host formal + bare RET | **High** | ABI crash |
| Triple global + host CF | **High** | wrong notify set |
| Distinct 0x10c vs 0x114 | **High** | wrong method |
| Product method English (OnLost/OnReset) | **Low** | wrong domain label |
| Holder product class names | **Low** | wrong subsystem map |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// GfxDevice_Reset @ 0x0075f153
EDX = [device+0x760]
ESI = [EDX+4]
CALL FUN_0074f0c0

// FUN_0073d8d0 vector walk
for each elem in [EAX+4 .. EAX+8) stride 0x14:
  ESI = *elem
  CALL FUN_0074f0c0
  // then nested ptr walk FUN_00752640

// Body
for G in {DAT_00afe034, DAT_00afe01c, DAT_00afe010}:
  if G && G->iface(+0xc): G->iface->vtbl[+0x10c](iface)
if ESI->iface(+0xc): ESI->iface->vtbl[+0x114](iface)
RET
```

---

## 4. Surviving contract for AutoCore

Port as **ESI-host leaf**: optional notify of three global holder ifaces at **vtbl+0x10c**, then host iface at **vtbl+0x114**. Do **not** invent product OnLost/OnReset names without PDB/strings. Do **not** unify with `FUN_0040d340` (different slot / subset).
