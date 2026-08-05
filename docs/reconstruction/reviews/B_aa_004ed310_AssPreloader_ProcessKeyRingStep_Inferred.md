# Review B (skeptical / adversarial): `aa_004ed310` AssPreloader_ProcessKeyRingStep_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ed310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-A) |
| **Counterpart** | `reviews/A_aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | stdcall / RET N cleans 3 args | **Falsified** — all exits plain `C3`; callers `ADD ESP,0xC` |
| 2 | thiscall on AssPreloader (ECX=this) | **Falsified** — ring is stack arg0; preloader loaded from global for nested only |
| 3 | Blocking full drain always | **Falsified** — returns 0 on enqueue and on wait; cooperative step |
| 4 | Always erases every key | **Falsified** — only tracked keys erased; others advanced or yield |
| 5 | recurse=1 on is-tracked | **Falsified** — `PUSH 0; CALL 00971900` |
| 6 | CONCAT31 returns multi-byte status | **Overstated** — high bytes garbage; sealed contract is **AL** 0/1 |
| 7 | Scaffold VOG_DEBUG plate | **Rejected** — no product evidence |
| 8 | Product method English exact | **Overstated** — `_Inferred` structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 3-arg + plain RET + AL | **High** | Stack imbalance |
| Global +0x6c gate | **High** | Wrong enable path |
| Tracked-erase / enqueue-yield CF | **High** | Infinite loop / missed preload |
| Nested ECX from global preloader | **High** | Wrong this on AssPreloader ops |
| Product English | **Inferred** | Naming only |
| Nested product of 0075d610/00971a20 | **Open** | Mislabel ready vs present |
| Runtime | **Open** | Race under concurrent enqueue |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  gate DAT_00d1f050+0x6c; clamp cursor; page-map loop;
  00971900(0) → erase path; else 0075d610 / 00971a20 / 009717a0;
  return AL 0/1

bytes:
  MOV EAX,[DAT_00d1f050]; CMP [EAX+6C],0 → AL=1 early
  nested: MOV ECX,[cache+6C]; PUSH 0; PUSH slot; CALL 00971900
  erase: MOV ECX, cur_container; CALL 0043df90
  exits: XOR AL,AL / MOV AL,1; ADD ESP,8; RET

caller:
  three pushes; CALL; ADD ESP,0C; TEST AL,AL
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF; **bytes win** on cdecl + AL + gate.

---

## 4. Surviving contract for AutoCore

```
// AssPreloader key-ring cooperative step:
//   cdecl (ring*, char* flag, uint* cursor) → AL 1=done / 0=yield
//   gate: if *(DAT_00d1f050+0x6c)==0 return 1
//   tracked keys: erase from ring (EraseRange_Thiscall); if flag, pending remove
//   first unready when flag==0: EnqueueKeyAndDeps; flag=1; return 0
//   when flag==1 and still unready: return 0 (wait)
//   exhaust: cursor=0, flag=0, return 1
// Do NOT model as blocking full drain or as AssPreloader thiscall method.
// Do NOT invent stdcall RET 0xC.
// Do NOT pass recurse=1 into IsKeyTracked from this unit.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF and rejects stdcall / thiscall-method / full-drain / scaffold-name claims. Nested product residual remains → **accept-with-gaps**.
