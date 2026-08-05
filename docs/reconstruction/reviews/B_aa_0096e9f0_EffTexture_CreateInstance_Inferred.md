# Review B (skeptical / adversarial): `aa_0096e9f0` EffTexture_CreateInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e9f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-O) |
| **Counterpart** | `reviews/A_aa_0096e9f0_EffTexture_CreateInstance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra `FUN_0096e9f0(1 stack arg)` complete formals | **Falsified** — body `RET 0x14` (5 dwords) + **EBX dims\***; parent pushes five |
| 2 | ECX-thiscall factory | **Falsified** — no `MOV reg,ECX` this capture; freelist in EDI; object in EAX/ESI |
| 3 | Plain `RET` / cdecl without cleanup | **Falsified** — both exits `C2 14 00` |
| 4 | Dims only from stack | **Falsified** — explicit `[EBX]` / `[EBX+4]` copy onto stack local before `0096cad0` |
| 5 | Leak on init failure | **Falsified** — `PUSH 1; CALL [vtbl+0]` complete dtor before null return |
| 6 | Scaffold Named_effTexture product as PDB name | **Rejected** — structural `_Inferred` factory name only |
| 7 | Sole caller is create-or-assign | **Partial** — second xref @ `0096ee3e` (unnamed); still factory role |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX dims* + 5 stack + RET 0x14 | **High** | Stack smash / wrong dims |
| Freelist → ctor → init → fail dtor | **High** | Leak / bad object |
| Parent push map (skip p1 into EBX) | **High** | Arg shuffle on port |
| a0=format-ish / flags product | **Medium** | Wrong D3D args |
| Object size / RTTI English | **Open** | Type naming only |
| Runtime / bit-exact | **Open** | Device-dependent |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  alloc; optional ctor; optional init; fail dtor; return ptr

bytes / listing:
  MOV EDI,0x00d21930; CALL 0043f120
  CALL 0096bbb0 | XOR ESI
  pack [EBX]/[EBX+4]; CALL 0096cad0
  JL → PUSH 1; CALL [vtbl]; XOR EAX; RET 0x14
  MOV EAX,ESI; RET 0x14
```

Live decompile 2026-08-04 ≡ raw CF skeleton; **bytes win** on formals/cleanup.

---

## 4. Surviving contract for AutoCore

```
// Effect-texture factory:
//   EBX = const uint32_t dims[2]*  // width, height
//   5 stack dwords; RET 0x14
//   return object* or null
// Do NOT trust Ghidra 1-arg prototype.
// Do NOT treat as thiscall; freelist head is DAT_00d21930 via EDI.
// On init fail: complete dtor vtbl[0](this,1) then null — do not leak.
// Parent CreateOrAssignSlot forwards (p0,p2,p3,p4,p5) with EBX=p1.
// Do NOT invent full product names for a0..a4 without plates.
```

---

## 5. Verdict

Adversarial pass **confirms** A on factory ABI/CF and rejects 1-arg / thiscall / leak / scaffold claims. Residual formal English → **accept-with-gaps**.
