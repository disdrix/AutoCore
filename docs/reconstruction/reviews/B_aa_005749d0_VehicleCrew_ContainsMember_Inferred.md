# Review B (skeptical / adversarial): `aa_005749d0` VehicleCrew_ContainsMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005749d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md` |
| **Agent** | WQ9R-A OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns packed `CONCAT31` / non-zero garbage on miss | **Falsified** — miss path `xor al,al; ret 4`; hit `mov al,1` |
| 2 | Compares full 16-byte TFID | **Falsified** — only two dwords (`+0x164/+0x168` vs slot `+0/+4`) |
| 3 | Scans unbounded list | **Falsified** — hard stop after slot index `> 3` |
| 4 | `this` is the vehicle object itself always | **Falsified for mode 0xb** — ECX = `*(vehicle+0xCB0)` crew host |
| 5 | This is friendly-fire / faction math | **Falsified as sole role** — pure COID roster membership; faction is `vtbl+0x298` elsewhere |
| 6 | Only called from Client_RecvDestroyObject | **Falsified** — 8 callers / 14 xrefs including skill filter + gather |
| 7 | Slot stride is 8 (COID pair only) | **Falsified** — loop uses `shl eax,4` (0x10); twin writer uses `piVar3+4` |
| 8 | Product name is retail-known | **Unproven** — `_Inferred` |
| 9 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |
| 10 | Null candidate undefined | **Falsified** — explicit early return 0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| AL bool / RET 4 | **Confirmed** | Wrong port ABI |
| 4×0x10 @ +0x198 | **Confirmed** | Crew accept false negatives |
| COID offBase+0x164/0x168 | **Confirmed** | ID mismatch vs inventory TFID layout |
| Mode 0xb ECX = +0xCB0 | **Confirmed** | Wrong this → always miss |
| “VehicleCrew” English | **High structural / Inferred product** | Rename only if RTTI appears |
| Slot payload beyond COID | Open | Port of insert twin may need object* field |

---

## 3. Cross-check

```
005749d0:     null→0; load COID; for i=0..3 cmp this+0x198/19c; AL bool; ret 4
005755b0:     if !Contains(member): find free slot (0xFFFFFFFF pair); write COID; store obj*; count++
00574a90:     find matching COID; zero slot field; FUN_00520330
0058a810 0xb: same veh OR (veh+0xCB0 && Contains(candVeh))
0054ff00:     skill+0x615&0x20 path calls Contains with host from caster chain
a_0058d330:   mode 0xb labeled "Same vehicle / plant crew" with FUN_005749d0
```

**Attack on “decompiler return (uint)uVar3<<8 means non-bool”:** `uVar3` is decompiler residue from `slot*0x10 >> 8` on a value always `< 0x40`. Epilogue never uses it — pure AL.

**Attack on “+0xCB0 is not crew”:** insert twin and filter both gate on non-null `+0xCB0` before calling this unit; insert writes the same `+0x198` table this unit reads.

---

## 4. Surviving contract for AutoCore

```
// CrewHost partial:
//   +0x198 slot[4]{ coidLo, coidHi, ... }  // stride 0x10

bool VehicleCrew_ContainsMember_Inferred(CrewHost* host, Object* candidate) {
  if (!candidate) return false;
  int off = *(int*)(*(int*)((char*)candidate + 4) + 4);
  int lo = *(int*)(off + 0x164 + (int)candidate);
  int hi = *(int*)(off + 0x168 + (int)candidate);
  for (int i = 0; i < 4; i++) {
    int* slot = (int*)((char*)host + 0x198 + i * 0x10);
    if (slot[0] == lo && slot[1] == hi) return true;
  }
  return false;
}
```

Port notes:
- Mode 0xb: check same `vtbl+0x210` vehicle first; only then crew host at `vehicle+0xCB0`.
- Keep 4-slot cap and 0x10 stride.
- Pair with insert `FUN_005755b0` / clear `FUN_00574a90` for full roster CRUD.

---

## 5. Gaps

1. Product English / demangle for host type.
2. Slot bytes `+8/+0xC` English (object* from writer).
3. Full set of object types stored as “members.”
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
