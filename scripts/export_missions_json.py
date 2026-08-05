"""
PLATE: Export all Auto Assault missions to JSON + standalone HTML viewer.

What it does:
  Merges missions.glm (narrative + requirements XML) with clonebase.wad mission
  records (giver NPC, gates, prereqs, rewards, objective XP/credits/positions)
  and resolves referenced CBIDs to ShortDesc/UniqueName. Writes compact JSON and
  embeds it into tools/mission-viewer HTML for offline browsing.

Examples:
  python scripts/export_missions_json.py
  python scripts/export_missions_json.py --limit 50
  python scripts/export_missions_json.py --no-names --out-json tmp/missions.json

Requires: missions.glm + clonebase.wad under AA_INSTALL (or --glm / --wad).
"""

from __future__ import annotations

import argparse
import json
import re
import struct
import sys
import xml.etree.ElementTree as ET
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

sys.path.insert(0, str(Path(__file__).resolve().parent))
from aa_paths import default_clonebase, default_missions_glm, repo_root  # noqa: E402

MISSION_TYPE_NAMES = {
    -1: "NonRandom",
    0: "Destroy",
    1: "Defend",
    2: "Escort",
    3: "Race",
    4: "Sneak",
    5: "Spy",
    6: "Deliver",
    7: "Collect",
    8: "Pickup",
    9: "Craft",
    255: "NonRandom",
}

KNOWN_CLONE_TYPES = {
    0, 1, 3, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36,
    38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72,
}

# MissionObjective.ReadNew size in bytes (after Mission header numObjectives)
OBJECTIVE_RECORD_SIZE = 320


def utf16_at(data: bytes, off: int, nchars: int = 65) -> str:
    chars: list[str] = []
    for k in range(nchars):
        if off + k * 2 + 1 >= len(data):
            break
        ch = struct.unpack_from("<H", data, off + k * 2)[0]
        if ch == 0:
            break
        if 32 <= ch < 127:
            chars.append(chr(ch))
        else:
            chars.append("?")
    return "".join(chars)


def looks_like_name(s: str) -> bool:
    if len(s) < 2:
        return False
    if not re.match(r"^[A-Za-z0-9_./\- ]+$", s):
        return False
    return any(c.isalpha() for c in s)


def text_child(elem: ET.Element | None, tag: str) -> str | None:
    if elem is None:
        return None
    child = elem.find(tag)
    if child is None or child.text is None:
        return None
    return child.text


def int_child(elem: ET.Element | None, tag: str, default: int | None = None) -> int | None:
    raw = text_child(elem, tag)
    if raw is None or raw == "":
        return default
    try:
        return int(float(raw))
    except ValueError:
        return default


def float_child(elem: ET.Element | None, tag: str, default: float | None = None) -> float | None:
    raw = text_child(elem, tag)
    if raw is None or raw == "":
        return default
    try:
        return float(raw)
    except ValueError:
        return default


def bool_child(elem: ET.Element | None, tag: str, default: bool | None = None) -> bool | None:
    v = int_child(elem, tag, None)
    if v is None:
        return default
    return v != 0


def omit_empty(d: dict[str, Any]) -> dict[str, Any]:
    """Drop None, empty strings, empty lists, and common sentinel -1 values for optional IDs."""
    out: dict[str, Any] = {}
    for k, v in d.items():
        if v is None:
            continue
        if v == "":
            continue
        if v == []:
            continue
        if isinstance(v, dict):
            nested = omit_empty(v)
            if nested:
                out[k] = nested
            continue
        out[k] = v
    return out


def find_mission_blocks(data: bytes) -> list[tuple[int, int]]:
    blocks: list[tuple[int, int]] = []
    idx = 0
    while True:
        start = data.find(b"<Mission ", idx)
        if start < 0:
            break
        end = data.find(b"</Mission>", start)
        if end < 0:
            break
        end += len(b"</Mission>")
        blocks.append((start, end))
        idx = end
    return blocks


def parse_pipe_ids(raw: str | None) -> list[int]:
    if not raw:
        return []
    out: list[int] = []
    for part in raw.split("|"):
        part = part.strip()
        if not part:
            continue
        try:
            out.append(int(part))
        except ValueError:
            continue
    return out


def parse_requirement(req_el: ET.Element) -> dict[str, Any]:
    rtype = (req_el.get("type") or "unknown").lower()
    slot = int(req_el.get("slot") or 0)
    req: dict[str, Any] = {"type": rtype, "slot": slot}

    if rtype == "kill":
        req.update(
            omit_empty(
                {
                    "numToKill": int_child(req_el, "NumToKill"),
                    "targetCbid": int_child(req_el, "CBID", -1),
                    "continentCbid": int_child(req_el, "ContinentCBID", -1),
                    "allowedType": int_child(req_el, "AllowedType", -1),
                    "allowedClass": int_child(req_el, "AllowedClass", -1),
                    "minLevel": int_child(req_el, "ReqireLevelMin", -1),
                    "maxLevel": int_child(req_el, "RequireLevelMax", -1),
                    "trackDamage": bool_child(req_el, "TrackDamage"),
                    "targetIsTemplateVehicle": bool_child(req_el, "TargetIsTemplateVehicle"),
                    "targetIsFaction": bool_child(req_el, "TargetIsFaction"),
                    "targetIsPlayer": bool_child(req_el, "TargetIsPlayer"),
                    "negativeKill": bool_child(req_el, "NegativeKill"),
                    "maxEscortDistance": float_child(req_el, "MaxEscortDistance"),
                }
            )
        )
    elif rtype == "kill_aggregate":
        targets = parse_pipe_ids(text_child(req_el, "CBID"))
        templates = parse_pipe_ids(text_child(req_el, "TEMPLATEID"))
        req.update(
            omit_empty(
                {
                    "numToKill": int_child(req_el, "NumToKill"),
                    "targets": targets,
                    "templateTargets": templates,
                    "continentCbid": int_child(req_el, "ContinentCBID", -1),
                    "allowedType": int_child(req_el, "AllowedType", -1),
                    "targetIsFaction": bool_child(req_el, "TargetIsFaction"),
                    "negativeKill": bool_child(req_el, "NegativeKill"),
                    "shortDescription": text_child(req_el, "ShortDescription"),
                }
            )
        )
    elif rtype == "collect":
        optional = [int(el.text) for el in req_el.findall("OptionalTargetCBID") if el.text]
        req.update(
            omit_empty(
                {
                    "itemCbid": int_child(req_el, "CBID", -1),
                    "numToCollect": int_child(req_el, "NumToCollect"),
                    "continentCbid": int_child(req_el, "ContinentCBID", -1),
                    "allowedType": int_child(req_el, "AllowedType", -1),
                    "allowedClass": int_child(req_el, "AllowedClass", -1),
                    "minLevel": int_child(req_el, "ReqireLevelMin", -1),
                    "maxLevel": int_child(req_el, "RequireLevelMax", -1),
                    "targetIsPlayer": bool_child(req_el, "TargetIsPlayer"),
                    "targetIsTemplateVehicle": bool_child(req_el, "TargetIsTemplateVehicle"),
                    "optionalDropPercent": float_child(req_el, "OptionalDropPercent"),
                    "takeItems": bool_child(req_el, "TakeAllItems"),
                    "giveToAllConvoyMembers": bool_child(req_el, "GiveToAllConvoyMembers"),
                    "optionalTargets": optional,
                }
            )
        )
    elif rtype == "deliver":
        req.update(
            omit_empty(
                {
                    "itemCbid": int_child(req_el, "CBIDItem", -1),
                    "numToDeliver": int_child(req_el, "NumToDeliver"),
                    "npcTargetCbid": int_child(req_el, "TargetNPCCBID", -1),
                    "continentId": int_child(req_el, "ContinentID", -1),
                    "giveItemAtStart": bool_child(req_el, "GiveItemAtStart"),
                    "takeItemAtEnd": bool_child(req_el, "TakeItemAtEnd"),
                    "npcTargetCompletes": bool_child(req_el, "NPCTargetCompletes"),
                }
            )
        )
    elif rtype == "patrol":
        targets = [
            int(el.text)
            for el in req_el.findall("GenericTargetCOID")
            if el.text is not None and el.text != ""
        ]
        req.update(
            omit_empty(
                {
                    "continentCbid": int_child(req_el, "ContinentCBID", -1),
                    "autoComplete": bool_child(req_el, "AutoComplete"),
                    "autoCompleteDistance": float_child(req_el, "AutoCompleteDistance"),
                    "autoFail": bool_child(req_el, "AutoFail"),
                    "autoFailDistance": float_child(req_el, "AutoFailDistance"),
                    "laps": int_child(req_el, "Laps", 1),
                    "targets": targets,
                }
            )
        )
    elif rtype == "useitem":
        req.update(
            omit_empty(
                {
                    "primaryCoid": int_child(req_el, "PrimaryCOID", -1),
                    "primaryCbid": int_child(req_el, "PrimaryCBID", -1),
                    "primaryDestroy": bool_child(req_el, "PrimaryDestroy"),
                    "primaryInWorld": bool_child(req_el, "PrimaryInWorld"),
                    "primaryUseText": text_child(req_el, "PrimaryUseText"),
                    "primaryGiveAtStart": bool_child(req_el, "PrimaryGiveAtStart"),
                    "primaryMultipleUse": bool_child(req_el, "PrimaryMultipleUse"),
                    "primaryExplode": bool_child(req_el, "PrimaryExplode"),
                    "primaryCompletedItem": int_child(req_el, "PrimaryCompletedItem", -1),
                    "secondaryCbid": int_child(req_el, "SecondaryCBID", -1),
                    "secondaryDestroy": bool_child(req_el, "SecondaryDestroy"),
                    "secondaryGiveAtStart": bool_child(req_el, "SecondaryGiveAtStart"),
                    "secondaryMultipleUse": bool_child(req_el, "SecondaryMultipleUse"),
                    "progressTime": int_child(req_el, "ProgressTime"),
                    "progressText": text_child(req_el, "ProgressText"),
                    "progressInterruptable": bool_child(req_el, "ProgressInterruptable"),
                    "progressInterruptText": text_child(req_el, "ProgressInterruptText"),
                    "completeText": text_child(req_el, "CompleteText"),
                    "completedItem": int_child(req_el, "CompleteItem", -1),
                    "completedMission": int_child(req_el, "CompletedMission", -1),
                    "repeatCount": int_child(req_el, "RepeatCount", 1),
                    "continentId": int_child(req_el, "ContinentID", -1),
                }
            )
        )
    elif rtype == "money":
        req.update(omit_empty({"moneyNeeded": int_child(req_el, "MoneyNeeded")}))
    elif rtype == "stunt":
        req.update(
            omit_empty(
                {
                    "height": float_child(req_el, "Height"),
                    "distance": float_child(req_el, "MaxEscortDistance"),
                    "time": float_child(req_el, "Time"),
                }
            )
        )
    elif rtype == "mission":
        req.update(
            omit_empty(
                {
                    "missionIds": parse_pipe_ids(text_child(req_el, "IDs")),
                    "countNeeded": int_child(req_el, "CountNeeded"),
                    "idsAreMedals": bool_child(req_el, "IDsAreMedals"),
                }
            )
        )
    elif rtype == "km":
        req.update(
            omit_empty(
                {
                    "distanceNeeded": float_child(req_el, "DistanceNeeded"),
                    "mode": int_child(req_el, "Mode"),
                }
            )
        )
    elif rtype == "timeplayed":
        secs = int_child(req_el, "SecondsPlayed")
        mins = int_child(req_el, "MinutesPlayed")
        if secs is None and mins is not None:
            secs = mins * 60
        req.update(
            omit_empty(
                {
                    "secondsPlayed": secs,
                    "useTotal": bool_child(req_el, "UseTotal"),
                    "failTimer": bool_child(req_el, "FailTimer"),
                    "showTimer": bool_child(req_el, "ShowTimer"),
                    "timerText": text_child(req_el, "TimerText"),
                }
            )
        )
    elif rtype == "characterlevel":
        req.update(omit_empty({"requiredLevel": int_child(req_el, "CharacterLevel")}))
    elif rtype == "escort":
        req.update(
            omit_empty(
                {
                    "skillId": int_child(req_el, "SkillID"),
                    "skillLevel": int_child(req_el, "SkillLevel"),
                    "failOnSummonDeath": bool_child(req_el, "FailOnDeath"),
                    "failDistance": float_child(req_el, "MaxDistance"),
                    "continentCbid": int_child(req_el, "ContinentCBID", -1),
                    "completionCoid": int_child(req_el, "CompletionCOID", -1),
                    "completionDistance": float_child(req_el, "CompletionPatrolDistance"),
                    "failCoid": int_child(req_el, "FailCOID", -1),
                    "failPatrolDistance": float_child(req_el, "FailPatrolDistance"),
                    "startEscort": bool_child(req_el, "StartEscort"),
                    "endEscort": bool_child(req_el, "EndEscort"),
                }
            )
        )
    elif rtype == "crazytaxi":
        req.update(
            omit_empty(
                {
                    "continentCbid": int_child(req_el, "ContinentCBID", -1),
                    "vehicleMaxVec": float_child(req_el, "VehicleMaxVec"),
                    "radiusOfStop": float_child(req_el, "RadiusOfStop"),
                    "finishOnMissionCount": bool_child(req_el, "MissionStopLimit"),
                    "finishMissionCount": int_child(req_el, "MissionStopCount"),
                    "giveMoney": bool_child(req_el, "GiveMoney"),
                    "giveExp": bool_child(req_el, "GiveExp"),
                }
            )
        )
    else:
        # Fallback: capture child tags as raw fields for unknown types
        raw: dict[str, str] = {}
        for child in list(req_el):
            if child.tag and child.text is not None:
                raw[child.tag] = child.text
        if raw:
            req["raw"] = raw

    # Normalize sentinel -1 optional IDs away for cleaner JSON
    for key in list(req.keys()):
        if key.endswith(("Cbid", "Coid", "Id", "Item")) or key in {
            "targetCbid",
            "itemCbid",
            "npcTargetCbid",
            "primaryCbid",
            "primaryCoid",
            "secondaryCbid",
            "continentCbid",
            "continentId",
            "completionCoid",
            "failCoid",
            "primaryCompletedItem",
            "completedItem",
            "completedMission",
            "allowedType",
            "allowedClass",
            "minLevel",
            "maxLevel",
        }:
            if req.get(key) == -1:
                del req[key]
    return req


def _sanitize_mission_xml(xml_bytes: bytes) -> bytes:
    """Best-effort fixes for retail mission XML that is not strict XML."""
    text = xml_bytes.decode("utf-8", "replace")
    # Strip illegal control chars
    text = re.sub(r"[\x00-\x08\x0b\x0c\x0e-\x1f]", "", text)
    # Escape bare ampersands that are not entities
    text = re.sub(r"&(?!(?:[a-zA-Z]+|#[0-9]+|#x[0-9a-fA-F]+);)", "&amp;", text)
    # Drop invalid UTF-8 replacement leftovers in tags if any
    return text.encode("utf-8")


def parse_glm_mission(xml_bytes: bytes) -> dict[str, Any] | None:
    # GLM may contain HTML-like entities; ET is fine for well-formed mission XML.
    try:
        root = ET.fromstring(xml_bytes)
    except ET.ParseError:
        cleaned = _sanitize_mission_xml(xml_bytes)
        try:
            root = ET.fromstring(cleaned)
        except ET.ParseError as exc:
            print(f"  XML parse error: {exc}", file=sys.stderr)
            return None

    mid = int(root.get("ID") or 0)
    name = root.get("name") or ""
    objectives: list[dict[str, Any]] = []
    req_types: set[str] = set()

    for obj_el in root.findall("Objective"):
        seq = int(obj_el.get("sequence") or 0)
        requirements = [parse_requirement(r) for r in obj_el.findall("Requirement")]
        for r in requirements:
            req_types.add(r["type"])
        objectives.append(
            omit_empty(
                {
                    "sequence": seq,
                    "objectiveId": int(obj_el.get("ID") or 0),
                    "name": obj_el.get("name") or "",
                    "map": obj_el.get("map") or "",
                    "title": text_child(obj_el, "Title"),
                    "externalText": text_child(obj_el, "ExternalText"),
                    "defaultText": text_child(obj_el, "DefaultText"),
                    "completeCount": int_child(obj_el, "CompleteCount", 0),
                    "requirements": requirements,
                }
            )
        )

    objectives.sort(key=lambda o: o.get("sequence", 0))

    mission = omit_empty(
        {
            "id": mid,
            "name": name,
            "title": text_child(root, "Title") or name,
            "internal": text_child(root, "Internal"),
            "description": text_child(root, "Description"),
            "onLineAccept": text_child(root, "OneLineAccept") or text_child(root, "OnLineAccept"),
            "onLineReject": text_child(root, "OneLineReject") or text_child(root, "OnLineReject"),
            "notCompleteText": text_child(root, "NotCompleteText"),
            "completeText": text_child(root, "CompleteText"),
            "failText": text_child(root, "FailText"),
            "coreMission": bool_child(root, "CoreMission", False),
            "requirementsOredGlm": int_child(root, "RequirementOred", 0),
            "requirementsNegativeGlm": int_child(root, "RequirementNegative", 0),
            "objectives": objectives,
            "requirementTypes": sorted(req_types),
        }
    )
    return mission


def parse_wad_mission_at(data: bytes, j: int) -> dict[str, Any] | None:
    """Parse Mission.Read fields starting at record offset j (CloneBaseId/Id)."""
    if j < 0 or j + 320 > len(data):
        return None
    mid = struct.unpack_from("<i", data, j)[0]
    name = utf16_at(data, j + 4, 65)
    if not looks_like_name(name):
        return None
    typ = data[j + 4 + 130]
    base = j + 4 + 130 + 2
    npc = struct.unpack_from("<i", data, base)[0]
    priority = struct.unpack_from("<i", data, base + 4)[0]
    req_race = struct.unpack_from("<h", data, base + 8)[0]
    req_class = struct.unpack_from("<h", data, base + 10)[0]
    req_lvl_min = struct.unpack_from("<i", data, base + 12)[0]
    req_lvl_max = struct.unpack_from("<i", data, base + 16)[0]
    req_missions = list(struct.unpack_from("<4i", data, base + 20))
    p = base + 20 + 16
    is_rep = struct.unpack_from("<h", data, p)[0]
    p += 2
    p += 2  # pad
    items = list(struct.unpack_from("<4i", data, p))
    p += 16
    item_templates = list(struct.unpack_from("<4i", data, p))
    p += 16
    item_values = list(struct.unpack_from("<4f", data, p))
    p += 16
    item_is_kit = list(struct.unpack_from("<4h", data, p))
    p += 8
    item_qty = list(struct.unpack_from("<4i", data, p))
    p += 16
    auto = struct.unpack_from("<h", data, p)[0]
    p += 2
    aoo = struct.unpack_from("<h", data, p)[0]
    p += 2
    continent = struct.unpack_from("<i", data, p)[0]
    p += 4
    # Achievement, Discipline, DisciplineValue, RewardDiscipline,
    # RewardDisciplineValue, RewardUnassignedDisciplinePoints, RequirementEventId
    achievement, discipline, discipline_value, reward_discipline, reward_discipline_value, reward_unassigned, req_event = (
        struct.unpack_from("<7i", data, p)
    )
    p += 28
    target_level = struct.unpack_from("<h", data, p)[0]
    p += 2
    p += 2  # pad
    ored = struct.unpack_from("<i", data, p)[0]
    neg = struct.unpack_from("<i", data, p + 4)[0]
    region = struct.unpack_from("<i", data, p + 8)[0]
    pocket = struct.unpack_from("<i", data, p + 12)[0]
    nobj_byte = data[p + 16]
    p += 17
    p += 7  # pad to align with Mission.Read (NumberOfObjectives + 7)
    # After NumberOfObjectives byte + 7 pad, next is numOfObjective i32
    # Recompute from known layout for safety:
    # j + 312 = numOfObjective (see plan)
    num_obj_off = j + 312
    if num_obj_off + 4 > len(data):
        return None
    num_obj = struct.unpack_from("<i", data, num_obj_off)[0]
    if num_obj < 0 or num_obj > 64:
        # fallback to byte count
        num_obj = nobj_byte

    objectives_wad: list[dict[str, Any]] = []
    obj_off = num_obj_off + 4
    for i in range(num_obj):
        if obj_off + OBJECTIVE_RECORD_SIZE > len(data):
            break
        quest_id, obj_id = struct.unpack_from("<ii", data, obj_off)
        sequence = data[obj_off + 8]
        obj_name = utf16_at(data, obj_off + 10, 65)
        map_name = utf16_at(data, obj_off + 140, 65)
        world_pos, cont_obj = struct.unpack_from("<ii", data, obj_off + 272)
        layer = data[obj_off + 280]
        xp, credits, attrib, skill, return_npc = struct.unpack_from("<5i", data, obj_off + 284)
        xp_index, credits_index = struct.unpack_from("<hh", data, obj_off + 304)
        xp_scaler, xp_bal, credit_scaler = struct.unpack_from("<3f", data, obj_off + 308)
        objectives_wad.append(
            omit_empty(
                {
                    "sequence": sequence,
                    "questId": quest_id,
                    "objectiveId": obj_id,
                    "name": obj_name,
                    "map": map_name,
                    "worldPosition": world_pos,
                    "continentObject": cont_obj,
                    "layerIndex": layer,
                    "xp": xp,
                    "credits": credits,
                    "attribPoints": attrib,
                    "skillPoints": skill,
                    "returnToNpc": return_npc,
                    "xpIndex": xp_index,
                    "creditsIndex": credits_index,
                    "xpScaler": xp_scaler,
                    "xpBalanceScaler": xp_bal,
                    "creditScaler": credit_scaler,
                }
            )
        )
        obj_off += OBJECTIVE_RECORD_SIZE

    type_id = typ if typ != 255 else -1
    rewards = []
    for i in range(4):
        if items[i] != 0 and items[i] != -1:
            rewards.append(
                omit_empty(
                    {
                        "itemCbid": items[i],
                        "template": item_templates[i] if item_templates[i] not in (0, -1) else None,
                        "value": item_values[i],
                        "isKit": bool(item_is_kit[i]),
                        "quantity": item_qty[i],
                    }
                )
            )

    return omit_empty(
        {
            "id": mid,
            "name": name,
            "typeId": type_id,
            "type": MISSION_TYPE_NAMES.get(typ, MISSION_TYPE_NAMES.get(type_id, f"Type{typ}")),
            "npcGiverCbid": npc if npc not in (0, -1) else None,
            "priority": priority,
            "reqRace": req_race,
            "reqClass": req_class,
            "reqLevelMin": req_lvl_min,
            "reqLevelMax": req_lvl_max,
            "reqMissionIds": [m for m in req_missions if m not in (0, -1)],
            "isRepeatable": bool(is_rep),
            "autoAssign": bool(auto),
            "activeObjectiveOverride": aoo,
            "continent": continent if continent not in (0, -1) else None,
            "achievement": achievement if achievement not in (0, -1) else None,
            "discipline": discipline if discipline not in (0, -1) else None,
            "disciplineValue": discipline_value if discipline_value else None,
            "rewardDiscipline": reward_discipline if reward_discipline not in (0, -1) else None,
            "rewardDisciplineValue": reward_discipline_value if reward_discipline_value else None,
            "rewardUnassignedDisciplinePoints": reward_unassigned if reward_unassigned else None,
            "requirementEventId": req_event if req_event not in (0, -1) else None,
            "targetLevel": target_level if target_level not in (0, -1) else None,
            "requirementsOred": ored,
            "requirementsNegative": neg,
            "region": region if region not in (0, -1) else None,
            "pocket": pocket if pocket not in (0, -1) else None,
            "numberOfObjectives": nobj_byte,
            "rewards": rewards,
            "objectivesWad": objectives_wad,
        }
    )


def find_wad_mission_by_name(data: bytes, name: str) -> dict[str, Any] | None:
    if not name:
        return None
    needle = name.encode("utf-16-le")
    start = 0
    while True:
        i = data.find(needle, start)
        if i < 0:
            return None
        j = i - 4
        if j >= 0:
            parsed = parse_wad_mission_at(data, j)
            if parsed and parsed.get("name") == name:
                return parsed
        start = i + 2


def find_wad_mission_by_id(data: bytes, mid: int, expected_name: str | None = None) -> dict[str, Any] | None:
    """Fallback when UTF-16 name search fails; requires plausible name field."""
    if mid <= 0:
        return None
    pat = struct.pack("<i", mid)
    idx = 0
    while True:
        j = data.find(pat, idx)
        if j < 0:
            return None
        parsed = parse_wad_mission_at(data, j)
        if parsed and looks_like_name(parsed.get("name") or ""):
            if expected_name and parsed["name"] != expected_name:
                # Accept if expected has spaces / casing only difference
                if parsed["name"].lower().replace(" ", "") != (expected_name or "").lower().replace(" ", ""):
                    idx = j + 4
                    continue
            return parsed
        idx = j + 4


def index_cbid_names(wad: bytes, needed: set[int]) -> dict[str, dict[str, str]]:
    """Index CloneBaseSpecific headers for needed CBIDs.

    Records are not always 4-byte aligned in the file image, so each CBID is
    located via binary find rather than a strided walk.
    """
    if not needed:
        return {}
    names: dict[str, dict[str, str]] = {}
    limit = len(wad) - 280
    for cbid in needed:
        pat = struct.pack("<i", cbid)
        idx = 0
        best: dict[str, str] | None = None
        best_score = (-1, -1, -1)
        while True:
            j = wad.find(pat, idx)
            if j < 0 or j > limit:
                break
            typ = struct.unpack_from("<i", wad, j + 4)[0]
            if typ in KNOWN_CLONE_TYPES:
                uname = utf16_at(wad, j + 12, 65)
                if looks_like_name(uname) and "?" not in uname:
                    short = utf16_at(wad, j + 12 + 130, 65)
                    if "?" in (short or ""):
                        short = ""
                    score = (
                        1 if short else 0,
                        1 if uname.startswith(("npc_", "gen_", "item_", "veh_", "cre_", "h_", "b_", "m_")) else 0,
                        len(uname),
                    )
                    if score > best_score:
                        best_score = score
                        best = {"short": short or uname, "unique": uname}
            idx = j + 1
        if best:
            names[str(cbid)] = best
    return names


def collect_referenced_cbids(missions: list[dict[str, Any]]) -> set[int]:
    needed: set[int] = set()

    def add(v: Any) -> None:
        if isinstance(v, int) and v > 0:
            needed.add(v)
        elif isinstance(v, list):
            for x in v:
                add(x)

    for m in missions:
        add(m.get("npcGiverCbid"))
        add(m.get("continent"))
        for r in m.get("rewards") or []:
            add(r.get("itemCbid"))
            add(r.get("template"))
        for obj in m.get("objectives") or []:
            add(obj.get("returnToNpc"))
            for req in obj.get("requirements") or []:
                for key, val in req.items():
                    if key in (
                        "targetCbid",
                        "itemCbid",
                        "npcTargetCbid",
                        "primaryCbid",
                        "secondaryCbid",
                        "continentCbid",
                        "continentId",
                        "primaryCompletedItem",
                        "completedItem",
                        "targets",
                        "templateTargets",
                        "optionalTargets",
                    ):
                        add(val)
    return needed


def name_for(names: dict[str, dict[str, str]], cbid: int | None) -> str | None:
    if cbid is None or cbid <= 0:
        return None
    entry = names.get(str(cbid))
    if not entry:
        return None
    return entry.get("short") or entry.get("unique")


def summarize_requirement(req: dict[str, Any], names: dict[str, dict[str, str]]) -> str:
    t = req.get("type", "?")
    if t == "patrol":
        n = len(req.get("targets") or [])
        laps = req.get("laps", 1)
        bits = [f"Patrol {n} waypoint(s)"]
        if laps and laps != 1:
            bits.append(f"{laps} laps")
        if req.get("autoComplete"):
            d = req.get("autoCompleteDistance")
            bits.append(f"auto-complete@{d}m" if d is not None else "auto-complete")
        return ", ".join(bits)
    if t == "kill":
        n = req.get("numToKill", "?")
        cbid = req.get("targetCbid")
        label = name_for(names, cbid) or (f"CBID {cbid}" if cbid else "target")
        if req.get("targetIsFaction"):
            label = f"faction {cbid}" if cbid else "faction"
        if req.get("targetIsPlayer"):
            label = "players"
        prefix = "Avoid killing" if req.get("negativeKill") else "Kill"
        return f"{prefix} {n} × {label}"
    if t == "kill_aggregate":
        n = req.get("numToKill", "?")
        targets = req.get("targets") or []
        if req.get("shortDescription"):
            return f"Kill {n}: {req['shortDescription']}"
        labels = [name_for(names, c) or str(c) for c in targets[:5]]
        extra = f" (+{len(targets)-5} more)" if len(targets) > 5 else ""
        return f"Kill {n} from [{', '.join(labels)}{extra}]"
    if t == "collect":
        n = req.get("numToCollect", "?")
        cbid = req.get("itemCbid")
        label = name_for(names, cbid) or (f"CBID {cbid}" if cbid else "item")
        return f"Collect {n} × {label}"
    if t == "deliver":
        npc = req.get("npcTargetCbid")
        npc_name = name_for(names, npc) or (f"CBID {npc}" if npc else "NPC")
        item = req.get("itemCbid")
        if item and item > 0:
            item_name = name_for(names, item) or f"CBID {item}"
            n = req.get("numToDeliver") or 1
            return f"Deliver {n} × {item_name} to {npc_name}"
        return f"Speak to {npc_name}"
    if t == "useitem":
        parts = []
        if req.get("primaryExplode"):
            parts.append("explode/place")
        elif req.get("primaryDestroy"):
            parts.append("destroy")
        elif req.get("primaryInWorld"):
            parts.append("use on world object")
        else:
            parts.append("use item")
        sec = req.get("secondaryCbid")
        prim = req.get("primaryCbid")
        if sec:
            parts.append(name_for(names, sec) or f"CBID {sec}")
        if prim:
            parts.append(f"on {name_for(names, prim) or f'CBID {prim}'}")
        if req.get("primaryCoid"):
            parts.append(f"COID {req['primaryCoid']}")
        rc = req.get("repeatCount") or 1
        if rc > 1:
            parts.append(f"×{rc}")
        return " ".join(parts)
    if t == "escort":
        return f"Escort to COID {req.get('completionCoid', '?')}"
    if t == "mission":
        ids = req.get("missionIds") or []
        kind = "medals" if req.get("idsAreMedals") else "missions"
        return f"Requires {kind}: {', '.join(map(str, ids))}"
    if t == "money":
        return f"Pay {req.get('moneyNeeded', '?')} credits"
    if t == "km":
        return f"Travel {req.get('distanceNeeded', '?')} distance"
    if t == "timeplayed":
        s = req.get("secondsPlayed")
        if s is not None:
            return f"Timer {s}s" + (" (fail)" if req.get("failTimer") else "")
        return "Time played"
    if t == "characterlevel":
        return f"Reach level {req.get('requiredLevel', '?')}"
    if t == "stunt":
        return f"Stunt height={req.get('height')} distance={req.get('distance')}"
    if t == "crazytaxi":
        return "Crazy taxi route"
    return t


def build_summary_flow(mission: dict[str, Any], names: dict[str, dict[str, str]]) -> str:
    parts: list[str] = []
    for obj in mission.get("objectives") or []:
        reqs = obj.get("requirements") or []
        if not reqs:
            title = obj.get("title") or f"Objective {obj.get('sequence')}"
            parts.append(title)
            continue
        parts.append(" + ".join(summarize_requirement(r, names) for r in reqs))
    return " → ".join(parts) if parts else ""


def merge_mission(glm: dict[str, Any], wad: dict[str, Any] | None, names: dict[str, dict[str, str]]) -> dict[str, Any]:
    m = dict(glm)
    if wad:
        for key in (
            "type",
            "typeId",
            "npcGiverCbid",
            "priority",
            "reqRace",
            "reqClass",
            "reqLevelMin",
            "reqLevelMax",
            "reqMissionIds",
            "isRepeatable",
            "autoAssign",
            "activeObjectiveOverride",
            "continent",
            "achievement",
            "discipline",
            "disciplineValue",
            "rewardDiscipline",
            "rewardDisciplineValue",
            "rewardUnassignedDisciplinePoints",
            "requirementEventId",
            "targetLevel",
            "requirementsOred",
            "requirementsNegative",
            "region",
            "pocket",
            "rewards",
        ):
            if key in wad and wad[key] is not None:
                m[key] = wad[key]
        # Merge objective WAD fields by sequence
        wad_by_seq = {o.get("sequence"): o for o in wad.get("objectivesWad") or []}
        merged_objs = []
        for obj in m.get("objectives") or []:
            o = dict(obj)
            w = wad_by_seq.get(o.get("sequence"))
            if w:
                for key in (
                    "worldPosition",
                    "continentObject",
                    "layerIndex",
                    "xp",
                    "credits",
                    "attribPoints",
                    "skillPoints",
                    "returnToNpc",
                    "xpIndex",
                    "creditsIndex",
                    "xpScaler",
                    "xpBalanceScaler",
                    "creditScaler",
                    "questId",
                ):
                    if key in w and w[key] is not None:
                        o[key] = w[key]
                if not o.get("name") and w.get("name"):
                    o["name"] = w["name"]
            # Attach human summaries on each requirement
            for req in o.get("requirements") or []:
                req["summary"] = summarize_requirement(req, names)
            merged_objs.append(o)
        m["objectives"] = merged_objs
        if wad.get("name") and wad["name"] != m.get("name"):
            m["wadNameMismatch"] = wad["name"]
    else:
        m["wadMissing"] = True
        for obj in m.get("objectives") or []:
            for req in obj.get("requirements") or []:
                req["summary"] = summarize_requirement(req, names)

    giver = m.get("npcGiverCbid")
    if giver:
        gn = name_for(names, giver)
        if gn:
            m["npcGiverName"] = gn
    m["summaryFlow"] = build_summary_flow(m, names)
    return omit_empty(m)


def load_template(template_path: Path) -> str:
    if not template_path.is_file():
        raise FileNotFoundError(f"Missing HTML template: {template_path}")
    return template_path.read_text(encoding="utf-8")


def embed_json_in_html(template: str, document: dict[str, Any]) -> str:
    payload = json.dumps(document, ensure_ascii=False, separators=(",", ":"))
    # Prevent </script> breakout
    payload = payload.replace("</", "<\\/")
    if "{{MISSIONS_JSON}}" not in template:
        raise ValueError("Template missing {{MISSIONS_JSON}} placeholder")
    return template.replace("{{MISSIONS_JSON}}", payload)


def export(
    glm_path: Path,
    wad_path: Path,
    out_json: Path,
    out_html: Path,
    template_path: Path,
    out_index: Path | None,
    limit: int | None,
    no_names: bool,
) -> int:
    if not glm_path.is_file():
        print(f"missing {glm_path}", file=sys.stderr)
        return 1
    if not wad_path.is_file():
        print(f"missing {wad_path}", file=sys.stderr)
        return 1

    print(f"Reading GLM {glm_path}...")
    glm_data = glm_path.read_bytes()
    blocks = find_mission_blocks(glm_data)
    print(f"  {len(blocks)} mission blocks")
    if limit:
        blocks = blocks[:limit]
        print(f"  limited to {len(blocks)}")

    glm_missions: list[dict[str, Any]] = []
    for start, end in blocks:
        parsed = parse_glm_mission(glm_data[start:end])
        if parsed:
            glm_missions.append(parsed)
    print(f"  parsed {len(glm_missions)} GLM missions")

    print(f"Reading WAD {wad_path}...")
    wad_data = wad_path.read_bytes()
    wad_by_name: dict[str, dict[str, Any]] = {}
    for i, gm in enumerate(glm_missions):
        name = gm.get("name") or ""
        if not name or name in wad_by_name:
            continue
        wad_m = find_wad_mission_by_name(wad_data, name)
        if wad_m is None:
            wad_m = find_wad_mission_by_id(wad_data, int(gm.get("id") or 0), name)
        if wad_m:
            wad_by_name[name] = wad_m
        if (i + 1) % 500 == 0:
            print(f"  WAD lookup progress {i + 1}/{len(glm_missions)} (unique hits {len(wad_by_name)})")
    wad_hits = sum(1 for gm in glm_missions if (gm.get("name") or "") in wad_by_name)
    print(f"  WAD matched {wad_hits}/{len(glm_missions)} missions ({len(wad_by_name)} unique names)")

    # Structural merge first (no names) so we can collect referenced CBIDs
    empty_names: dict[str, dict[str, str]] = {}
    structural = [
        merge_mission(gm, wad_by_name.get(gm.get("name") or ""), empty_names)
        for gm in glm_missions
    ]

    names: dict[str, dict[str, str]] = {}
    if not no_names:
        needed = collect_referenced_cbids(structural)
        print(f"Indexing {len(needed)} referenced CBIDs in clonebase...")
        names = index_cbid_names(wad_data, needed)
        print(f"  resolved {len(names)} names")

    merged = [
        merge_mission(gm, wad_by_name.get(gm.get("name") or ""), names)
        for gm in glm_missions
    ]

    # Build id→title map for prereq display
    id_title = {m["id"]: m.get("title") or m.get("name") for m in merged if "id" in m}
    for m in merged:
        prereqs = []
        for pid in m.get("reqMissionIds") or []:
            prereqs.append({"id": pid, "title": id_title.get(pid)})
        if prereqs:
            m["prerequisites"] = prereqs

    document = {
        "generatedAt": datetime.now(timezone.utc).isoformat(),
        "sourceGlm": str(glm_path),
        "sourceWad": str(wad_path),
        "missionCount": len(merged),
        "wadMatchCount": wad_hits,
        "names": names,
        "missions": merged,
    }

    out_json.parent.mkdir(parents=True, exist_ok=True)
    # Compact but readable enough for debugging
    out_json.write_text(
        json.dumps(document, ensure_ascii=False, separators=(",", ":")),
        encoding="utf-8",
    )
    print(f"Wrote {out_json} ({out_json.stat().st_size:,} bytes)")

    template = load_template(template_path)
    standalone = embed_json_in_html(template, document)
    out_html.parent.mkdir(parents=True, exist_ok=True)
    out_html.write_text(standalone, encoding="utf-8")
    print(f"Wrote {out_html} ({out_html.stat().st_size:,} bytes)")

    if out_index:
        # index.html loads missions.json via fetch (same template, placeholder becomes loader)
        index_html = template.replace(
            "const EMBEDDED_DATA = {{MISSIONS_JSON}};",
            "const EMBEDDED_DATA = null;",
        )
        # Ensure fetch path works when EMBEDDED_DATA is null
        if "const EMBEDDED_DATA = null;" not in index_html and "{{MISSIONS_JSON}}" in index_html:
            index_html = template.replace("{{MISSIONS_JSON}}", "null")
        out_index.write_text(index_html, encoding="utf-8")
        print(f"Wrote {out_index}")

    # Stats
    type_hist: dict[str, int] = {}
    for m in merged:
        for t in m.get("requirementTypes") or []:
            type_hist[t] = type_hist.get(t, 0) + 1
    print("Requirement types (missions containing):")
    for t, n in sorted(type_hist.items(), key=lambda x: -x[1]):
        print(f"  {t}: {n}")
    return 0


def main() -> int:
    root = repo_root()
    default_tools = root / "tools" / "mission-viewer"
    ap = argparse.ArgumentParser(description=__doc__.split("Examples:")[0].strip())
    ap.add_argument("--glm", type=Path, default=None)
    ap.add_argument("--wad", type=Path, default=None)
    ap.add_argument("--out-json", type=Path, default=default_tools / "missions.json")
    ap.add_argument(
        "--out-html",
        type=Path,
        default=default_tools / "mission-viewer-standalone.html",
    )
    ap.add_argument(
        "--out-index",
        type=Path,
        default=default_tools / "index.html",
        help="Write fetch-based index.html (set empty string to skip)",
    )
    ap.add_argument(
        "--template",
        type=Path,
        default=default_tools / "viewer-template.html",
    )
    ap.add_argument("--limit", type=int, default=None, help="Export only first N missions")
    ap.add_argument("--no-names", action="store_true", help="Skip CBID name resolution")
    args = ap.parse_args()

    out_index = args.out_index
    if str(out_index) in ("", "none", "-"):
        out_index = None

    return export(
        glm_path=args.glm or default_missions_glm(),
        wad_path=args.wad or default_clonebase(),
        out_json=args.out_json,
        out_html=args.out_html,
        template_path=args.template,
        out_index=out_index,
        limit=args.limit,
        no_names=args.no_names,
    )


if __name__ == "__main__":
    raise SystemExit(main())
