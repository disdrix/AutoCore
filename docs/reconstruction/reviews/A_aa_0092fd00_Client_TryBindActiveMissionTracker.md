# Review A (reconstruction fidelity): `aa_0092fd00` Client_TryBindActiveMissionTracker

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092fd00` |
| **VA** | `0x0092fd00` |
| **Canonical name** | `Client_TryBindActiveMissionTracker` |
| **Ghidra name** | `FUN_0092fd00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W21-Q) |
| **Counterpart** | `reviews/B_aa_0092fd00_Client_TryBindActiveMissionTracker.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind/clear the client's **active mission objective tracker** from a mission id:

```text
ch = client+0xe98
if !ch: return 0

if missionId != 0:
  node = CNDHash_LookupByKey(ch+0x548, missionId)
  if !node || !FUN_0059dc50(node, ch): return 0
else:
  if tracker(client+0x4d0)+0x10 == 0: return 1   // already idle

ok = FUN_0092a590(tracker, missionId)            // ECX=tracker, EAX=id
if ok && client+0x107c:
  if ui.vtbl+0x3d8(): ui.vtbl+0x448()
return ok
```

Shared post-mission helper: FailMission (EAX=0 after hash miss), MissionDialogHandleButton, convoy notify, etc.

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| EDI | Client* | `mov esi,[edi+0xe98]`; callers `MOV EDI,0xd1a840` |
| EAX | missionId | entry `mov ebx,eax`; callers load id into EAX |
| AL | bool success | `xor al,al` / `mov al,1` / binder result |
| Stack | none | body ends `ret` (range `…fd00`–`…fd84`) |

**Not** `__cdecl void` as bare Ghidra signature suggests.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0092fd00_*`, `Client_TryBindActiveMissionTracker.cpp` |
| Live decompile | Ghidra `decompile_function` @ `0x0092fd00` |
| Live bytes | `read_memory` 128 B @ entry — full body decoded |
| Call sites | `get_assembly_context` on all 9 xrefs |
| Callees | `FUN_0092a590`, `FUN_0059dc50` decompiled |
| Parent | `Client_RecvFailMission` dual residual lists this unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null character → 0 | **Yes** |
| Non-zero id → hash + gate | **Yes** (asm: ECX=node, push char) |
| Zero id + tracker idle → 1 no binder | **Yes** |
| Zero id + tracker busy → binder clear | **Yes** |
| Binder + optional UI 0x3d8/0x448 | **Yes** |
| Return binder AL | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = try bind/clear active mission tracker | **High** |
| EDI/EAX/AL ABI | **Confirmed** |
| Offsets `+0xe98`, `+0x548`, `+0x4d0`, `+0x10`, `+0x107c` | **Confirmed** |
| Name structural (no product string) | **High** |
| Gate `FUN_0059dc50` product English | **Open** |
| UI `+0x448` hide vs refresh English | **Tentative** (slot shared with hide paths) |
| Runtime | **Open** |

---

## 6. Gaps / open

1. Product name for tracker at `+0x4d0` and objective gate residual rules (`FUN_0059dc50`).
2. Exact semantic of mission UI `vtbl+0x448` in this context (refresh vs hide).
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — ABI + CF + offsets sealed; product English for gate/UI slot open.
