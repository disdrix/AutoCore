# Review B (skeptical / adversarial): `Client_EvalAutoPatrolWaypoint` @ `0x00929ec0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00929ec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00929ec0_Client_EvalAutoPatrolWaypoint.md` |
| **Verdict** | **accept** as game AutoPatrol eval; **reject** CRT-identity / no-op readings |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | CRT / compiler `identity` helper | **Falsified** — multi-stage mission client logic; Ghidra name `Client_EvalAutoPatrolWaypoint` |
| 2 | Pure out-param copy with no network | **Falsified** — optional `Client_SendSectorPacket` 0x20B3 |
| 3 | Index is a stack formal only | **Falsified** — **EAX** is waypoint index (`mov esi,eax`) |
| 4 | Always sends AutoPatrol | **Falsified** — gated by `mgr+0x102` and distance `mgr+0x104` |
| 5 | Opcode float `1.17303e-41` is a real float | **Falsified as float** — bit pattern of **0x20B3** reinterpreted |
| 6 | Packet size ≠ 0x18 | **Falsified** — constant 0x18 to SendSectorPacket |
| 7 | Resolves via wrong helper | **Falsified** — callee `Object_ResolveFromTFID` `0x004bb950` |
| 8 | Clean invents stages vs live decompile | **Falsified** — scaffold tracks plate |
| 9 | All failure paths leave out TFID uninitialized | **Falsified** — writes `DAT_00a158a0..ac` |
| 10 | Server must handle AutoPatrol as S2C in Client_PacketDispatch | **Falsified** — C2S only; dispatch comments note absence |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Real game code (not CRT) | **Confirmed** | Mis-skip dual / wrong queue |
| EAX index formal | **Confirmed** | Off-by-index if ported as stack-only |
| 0x20B3 / size 0x18 | **High** | Wrong C2S → patrol stuck |
| Distance gate uses player vtbl+0x1a0 pos | **High** (pattern) | Wrong origin → spam/miss packets |
| Object field +0x160 = TFID for packet | **High** | index 0x58*4 |
| `mgr+4` flag meaning | **Medium** | side-effect semantics |
| Full product type of patrol manager | **Medium** | layout dual residual |

---

## 3. Surviving contract for AutoCore

```
// EAX = waypointIndex (register formal)
// stack: patrolManager*, outTfid[16], outPos[3]
void Client_EvalAutoPatrolWaypoint(void* mgr, void* outTfid, float* outPos);

// On success: *outTfid = entry TFID; outPos = cached/refreshed XYZ
// On fail: *outTfid = invalid sentinel DAT_00a158a0
// Side effect (optional): C2S AutoPatrol
//   u32 opcode=0x20B3; u32 pad; TFID target from object+0x160
//   Client_SendSectorPacket(*(void**)mgr, 0x18, &pkt)
// Gates: mgr+0x102 enable; dist < *(float*)(mgr+0x104)
```

Port rule: server AutoPatrol must accept C2S 0x20B3; client must not expect S2C handler in PacketDispatch for this opcode.

---

## 4. Residual attacks / open

1. Scaffold files still named `identity` — documentation debt only.
2. Exact failure taxonomy when resolve succeeds but vtbl gates fail.
3. Live capture of AutoPatrol packet contents under real patrol missions.
4. Relationship of this path to `CVOGObjectiveRequirement_Patrol_*` / `CVOGHBMissionPatrol` ticks (call-graph residual).

**Verdict:** **accept** game CF; permanently discard CRT-identity interpretation of `aa_00929ec0`.
