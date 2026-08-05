# Review B (skeptical / adversarial): `aa_0043c550` GuardedVector_EraseFirstEqual

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-C) |
| **Counterpart** | `reviews/A_aa_0043c550_GuardedVector_EraseFirstEqual.md` |
| **Scratch** | `tmp/a_0043c550.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX=this thiscall only | **Falsified for this body** — container is **ESI**; callers load ESI from ECX+disp |
| 2 | cdecl / plain RET | **Falsified** — `RET 4` |
| 3 | Erases all matches | **Falsified** — first match only then leave |
| 4 | Always locks | **Falsified** — gated by `+0x2c` |
| 5 | Product name retail | **Overstated** — inferred `GuardedVector_*` |
| 6 | unaff_ESI is decompiler noise | **Falsified** — entry bytes use `[ESI+…]`; callers set ESI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI + RET 4 ABI | **High** | Wrong container / stack |
| CS offsets | **High** | Race / deadlock |
| First-equal erase CF | **High** | Stale resolver entry |
| Element type | **Medium** | Wrong equality |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Concurrent remove |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  unaff_ESI +0x2c gate; scan begin..begin+size; equal → EraseRange(idx,idx+1); AL

bytes:
  SUB ESP,0xC; CMP [ESI+0x2C],0
  EnterCS via [ESI+0x14]
  loop + CALL 0043c8c0 with EAX=ESI
  LeaveCS; MOV AL,BL; ADD ESP,0xC; RET 4

caller 00423e00:
  MOV ESI,ECX; ADD ESI,0x58; PUSH &key; CALL 0043c550
  plate: assManager.cpp "Removing resolver not found"
```

Live decompile ≡ raw. Only two xrefs, both resolver-removal paths.

---

## 4. Surviving contract for AutoCore

```
// First-equal erase under optional CS (assManager resolver list member):
//   ESI = GuardedVector header (+0x04 slots, +0x08 cap, +0x0c begin, +0x10 size,
//         +0x14 CS, +0x2c lockEnable)
//   stdcall (key*); RET 4; AL = found&erased
//   Port: scan ring, erase one via shorter-side EraseRange policy, first only.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/CS; element-type + product residual → **accept-with-gaps**.
