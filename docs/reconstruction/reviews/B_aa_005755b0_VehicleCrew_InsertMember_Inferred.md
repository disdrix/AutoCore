# Review B (skeptical / adversarial): `aa_005755b0` VehicleCrew_InsertMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005755b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_005755b0_VehicleCrew_InsertMember_Inferred.md` |
| **Agent** | WQ9D-D OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI; product name + caller graph open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `FUN_00520330(host)` only / sets host field | **Falsified** — `mov ecx, member; push host; call` → **member+0xCB0 = host** |
| 2 | Free slot is zeroed COID (0,0) | **Falsified** — free when `(lo & hi) == 0xFFFFFFFF` (both FFs) |
| 3 | Unbounded insert / dynamic vector slots | **Falsified** — hard 4-slot scan; capacity sum > 3 rejects |
| 4 | Skips Contains → allows duplicates | **Falsified** — Contains first; already-member → 0 |
| 5 | This is faction / TFID-16 table | **Falsified** — COID lo/hi only; same table as Contains dual |
| 6 | Decompiler `undefined4` return is full EAX payload | **Falsified** — success `mov al,1`; fail `xor al,al` |
| 7 | Always called from skill gather | **Unproven** — **0** direct CALL xrefs in Ghidra |
| 8 | Product name retail-known | **Unproven** — `_Inferred` |
| 9 | Runtime Confirmed | **Rejected** — no Launcher |
| 10 | Scaffold name `Named_VOG_DEBUG_STOP_*` is product | **Falsified as product** — debug string is assert path only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| AL bool / RET 4 | **Confirmed** | Wrong port ABI |
| 4×0x10 @ +0x198 + object* | **Confirmed** | Roster corruption |
| Capacity gate | **Confirmed** | Over-insert |
| Contains uniqueness | **Confirmed** | Dup slots |
| member+0xCB0 back-link | **Confirmed** | Mode 0xb host resolve breaks |
| host+0x1F4 COID vector push | **Confirmed** | Secondary list desync |
| “VehicleCrew” English | **High structural / Inferred product** | Rename only |
| Live callers | **Open** | May be dead code or indirect |

---

## 3. Cross-check

```
005749d0: null→0; COID scan 4×0x10 @+0x198; AL bool          // Contains
005755b0: capacity; !Contains; free FF pair; write; +CB0; vec; count++ // Insert
00574a90: find COID; clear slot; FUN_00520330 (clear path)     // Clear twin
0058a810 0xb: same veh OR Contains(*(veh+0xCB0), cand)         // consumer of Contains
00520330: *(this+0xCB0) = arg                                  // leaf setter
00418d70: vector append 8-byte element                         // COID push
```

**Attack on “decompiler FUN_00520330(param_1) means host+0xCB0 = ?”:**  
Setter is `*(this+0xCB0)=arg`. Call site loads **member** into ECX and **host** onto stack. Therefore **member** receives the crew-host pointer — matching mode 0xb reads of `vehicle+0xCB0` as crew host.

**Attack on “zero xrefs ⇒ function is fake / wrong VA”:**  
Body is real code (distinct callees, string, layout matching dualed Contains). Orphan status is a **gap**, not a CF reject.

---

## 4. Surviving contract for AutoCore

```
// CrewHost partial:
//   +0x198 slot[4]{ coidLo, coidHi, object*, ? }  // stride 0x10
//   +0x1D8 u8 count
//   +0x1E4 i32 bias
//   +0x1F4 vector<COID8>

bool VehicleCrew_InsertMember_Inferred(CrewHost* host, Object* member) {
  if ((int)host->count + host->bias > 3) return false;
  if (VehicleCrew_ContainsMember_Inferred(host, member)) return false;
  for (int i = 0; i < 4; i++) {
    auto& s = host->slot[i];
    if ((s.coidLo & s.coidHi) == 0xFFFFFFFFu) {
      load_coid(member, &s.coidLo, &s.coidHi);
      s.object = member;
      member->crewHostAtCB0 = host;   // FUN_00520330
      vector_push_coid(host->vecAt1F4, s.coidLo, s.coidHi);
      host->count++;
      return true;
    }
  }
  debug_stop("VOG_DEBUG_STOP");
  return false;
}
```

Port notes:
- Pair with Contains / Clear for full roster CRUD.  
- Preserve FF free sentinel (not zero).  
- Do not trust decompiler’s `FUN_00520330(host)` arity/this.  
- Mode 0xb gather still uses Contains, not Insert.

---

## 5. Gaps

1. Product English / demangle.  
2. Caller graph (0 direct xrefs).  
3. `+0x1E4` / `+0x1F4` product English.  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
