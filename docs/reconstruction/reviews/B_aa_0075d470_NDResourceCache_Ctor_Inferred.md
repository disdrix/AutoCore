# Review B (skeptical / adversarial): `aa_0075d470` NDResourceCache_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d470` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-B) |
| **Counterpart** | `reviews/A_aa_0075d470_NDResourceCache_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` stack formal |
| 2 | Decompiler omits return / formals in signature | **Partial** — decompile shows `int FUN(int)` correctly for return; Ghidra function sig was bare `undefined FUN(void)` — bytes win |
| 3 | Standalone heap object only | **Falsified** — sole caller passes `outer+0x0c`; embed placement |
| 4 | `DAT_00d1f050` is AssManager root | **Falsified** — outer `FUN_007543b0` sets `DAT_00d1f058=outer`; this unit publishes **embed** at +0x0c |
| 5 | CS flag at +0x54 is inside RTL_CRITICAL_SECTION | **Careful** — CS size 0x18 → +0x3c+0x18=+0x54 is **byte after** CS (lock-enable / inited flag), not SpinCount |
| 6 | Scaffold `Named_CalleeOf_*Client_Init*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB “NDResourceCache” English | **Careful** — structural from DAT plate + dual family; `_Inferred` only |
| 8 | Constructs full AssManager including resolvers | **Falsified** — resolvers live on outer `DAT_00d1f058` (+0x58 etc.); this is resource host only |
| 9 | Tree size field is +0x5c | **Falsified** — head ptr @+0x5c; size @+0x60 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout NestedHash/CS/tree/preloader | **High** | Member misaligned |
| DAT_00d1f050 vs DAT_00d1f058 roles | **High** | Wrong singleton for ensure/sweep |
| Product type English | **Low** | Naming only |
| Aux +0x2c..+0x38 / +0x64/+0x68 meaning | **Low** | Wrong field semantics |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_007543b0 (AssManager client):
//   DAT_00d1f058 = outer
//   FUN_0075d470(outer + 0x0c)   // this unit → DAT_00d1f050 = embed

// Downstream:
//   FUN_0075d3c0 EnsureAssPreloader(host)  // W33-O; zeros then ensure on +0x6c
//   FUN_00934420 "Preloading enabled" → DAT_00d1f050
//   NestedHash list head host+8 used by sweep / ensure seed
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 151 B hex seals offsets and `RET 4`.
Callee duals: NestedHash 0x14 (W34-E), StdTree node 0x1c (W16-G), EnsureAssPreloader (W33-O).

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
NDResourceCache* ctor(NDResourceCache* self) {
  DAT_00d1f050 = self;
  NestedHash_Ctor_Sentinel0x14(self);     // +0
  // zero +0x2c..+0x38
  InitializeCriticalSection(self+0x3c);
  *(u8*)(self+0x54) = 1;                  // post-CS flag
  // tree head @+0x5c via StdTree_AllocNode_0x1c + head self-link; size@+0x60=0
  // +0x64=0; +0x68=0; +0x6c=0
  AssManager_EnsureAssPreloader(self);
  return self;
}
// Embed at AssManager+0x0c; do not confuse with DAT_00d1f058 outer.
// Do not invent product English; pair with NestedHash / Ensure / Sweep duals.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/global/embed/callee order. Residual product plate + aux field meaning + runtime → **accept-with-gaps**.
