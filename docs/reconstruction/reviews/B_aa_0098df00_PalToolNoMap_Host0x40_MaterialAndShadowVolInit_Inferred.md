# Review B (skeptical / adversarial): `aa_0098df00` PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098df00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-A; wave36 residual) |
| **Counterpart** | `reviews/A_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `0098fd80` (single material only) | **Falsified** — three stages; also `PalVisibleShadowVolume.fx` ×2 |
| 2 | Stack formal host like sibling | **Falsified** — decompiler `in_EAX`; call site `FUN_0098df00()` with no push of host |
| 3 | ECX-thiscall | **Not evidenced** — Ghidra presents **EAX**, not ECX |
| 4 | Emissive same as `0098fd80` (0.4) | **Falsified** — this unit uses `DAT_00a0f70c` **0.2f** |
| 5 | Scaffold `Gfx_PalToolMaterialNoMap_0098df00` sole name | **Reject as complete** — omits shadow-volume stages |
| 6 | Multiple callers | **Falsified** — sole xref `0073cb1b` |
| 7 | Host size 0x30 | **Falsified** — caller `new(0x40)` + three 8-byte-aligned holders through `+0x38` |
| 8 | Returns OR of statuses | **Falsified** — constant `return 0` |
| 9 | Stage2/3 Solid colors identical | **Falsified** — stage2 Solid G=1; stage3 Solid B=1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sole caller + host size 0x40 | **Confirmed** | Wrong ownership |
| Slots +0x28/+0x30/+0x38 | **Confirmed** | Wrong layout |
| Host via EAX | **High** | Wrong ABI at call site |
| Plate strings (both effects) | **Confirmed** | Wrong binds |
| Color packs | **Confirmed** | Wrong viz |
| Constant return 0 | **High** | Wrong error model |
| Dual-shadow product role | **Tentative** | Naming/docs only |
| Helper thiscall ECX | **Probable** open | Port wiring |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + live + xrefs

- Live decompile **≡** raw body (no CF delta W37-A).
- Xref count 1: `FUN_0073c810` @ `0x0073cb1b` immediately after `unaff_EDI[10] = pvVar2`.
- Caller zeroes three holders before call — matches three-stage body.
- Contrast with `0098fd80` (slot9, 0x30, emissive 0.4): **different host family member**, same bootstrap parent.
- `analyze_function_complete` marks `in_EAX` as **phantom** — still required for semantics; do not drop host.

---

## 4. Surviving contract for AutoCore

```
// Port as EAX-host (or explicit C arg) three-stage post-ctor init:
uint32_t InitPalToolNoMapHost0x40(void *host /* size 0x40, EAX */) {
  // +0x28: PalToolMaterialNoMap.fx + DepthBias/GhostAlpha + Mat* (emis 1,0.2,0.2,1)
  // +0x30: PalVisibleShadowVolume.fx Solid(0,1,0,0.5) Wire(0,1,0,0.5) (ADV-corrected; not blue wire)
  // +0x38: PalVisibleShadowVolume.fx Solid(0,0,1,0.5) Wire(0,0,1,0.5)
  // each: null→-1 param handles; refcount-swap
  // return 0
}
// Do not invent product class English beyond plate strings.
// Pair with HostPtrTable12 slot10 allocation + FUN_00457b30 ctor (FUN_0073c810).
```

---

## 5. Verdict

Adversarial pass confirms A on three-stage ladder, EAX host, sole caller, sizes/slots, strings, distinct float packs vs sibling. Residual product English + dual-shadow intent + helper depth → **accept-with-gaps**.
