# Review B (skeptical / adversarial): `aa_0075de80` AssManager_SweepTrackedAssets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075de80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-O) |
| **Counterpart** | `reviews/A_aa_0075de80_AssManager_SweepTrackedAssets_Inferred.md` |
| **Scratch** | `tmp/a_0075de80.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void(void)` is full ABI | **Falsified** — bytes `RET 8`; two stack formals + ECX this |
| 2 | `operator_delete` never returns (decompiler WARNING) | **Falsified** — normal free then fallthrough; decompiler noise |
| 3 | Mode 2 always rescan-loops | **Falsified** — exit when `mode==2` regardless of destroy count |
| 4 | Mode 1 destroys assets in-loop | **Falsified** — mode 1 collects; destroy is mode≠1 unload / mode 2 age path |
| 5 | `thiscall` stack arg order reversed | **Falsified** — caller `FUN_007544f0` pushes `0x41200000` then `0` → age then mode? Wait: decompile shows `FUN_0075de80(0, 0x41200000)` as (mode, age)= (0, 10.0f). cdecl-looking display is thiscall with implicit this. |
| 6 | Product name `AssManager_SweepTrackedAssets` is retail | **Overstated** — **Inferred** from path string + CF |
| 7 | Scaffold `Named_assManager` is canonical | **Rejected** — string fragment only |
| 8 | Body is leaf | **Falsified** — many callees; worker classification |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + RET 8 | **High** | Wrong cleanup / stack smash in port |
| Mode 1 collect vs 2 age vs other unload | **High** | Wrong lifetime policy |
| List +0x8 / secondary +0x6c | **High** | Wrong field |
| Asset +0x10 idle / +0x1C stamp / CS +0x20 | **High** (index math) | Wrong idle/age test |
| Product method / mode enums | **Inferred** | Naming only |
| vtbl[0] exact product role | **Open** | Wrong release semantics |
| Runtime CS races | **Open** | Concurrent unload bugs |

---

## 3. Cross-check against raw + bytes

```
get_function_by_address: 0075de80 - 0075e2ce  → 0x54E
epilogue read_memory: C2 08 00 CC
prologue: 8B F1 (ESI=ECX)
live decompile ≡ raw 2026-07-23 body text
caller FUN_007544f0: FUN_0075de80(0, 0x41200000) → mode0 + 10.0f age
push site 0075e046: EAX container → FUN_0043e9e0 (W31-J sealed)
string site: assManager.cpp + 0x1BB via vog_LogMessage
```

Adversarial residual is product English + nested helper free + runtime — not CF/ABI.

---

## 4. Surviving contract for AutoCore

```
// AssManager tracked-asset sweep:
//   ECX = assManager*; stack = (int mode, float ageThreshold); RET 8
//   list head = this+0x08; optional secondary host = this+0x6c
//   mode 1: collect keys+asset* (+ optional secondary push under CS)
//   mode 2: single-pass age purge when idle (asset+0x10==0) and age>=threshold
//   other: hard unload idle; rescan while any destroyed this pass
//   do not invent vector::clear; do not trust decompiler void(void) / noreturn delete
//   nested PushBack is GuardedVector_PushBack_Stride2_U32U8 (EAX container)
```

---

## 5. Verdict

Adversarial pass confirms A’s sealed ABI/CF; product/runtime residual remains → **accept-with-gaps**.
